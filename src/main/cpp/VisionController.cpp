#include "VisionController.h"

VisionController::VisionController() {

    _navXSpeed = 200;
    _navX = new AHRS(frc::SPI::kMXP, _navXSpeed);
    _navX->Reset(); 

    _photonVision = new photonlib::PhotonCamera("photonvision");
    _photonResult = _photonVision->GetLatestResult();

    // assume camera is centered on robot
    _cameraToRobot = frc::Transform2d(frc::Pose2d(units::meter_t{0.0}, units::meter_t{0.0}, frc::Rotation2d()), 
        frc::Pose2d(units::meter_t{0.0}, units::meter_t{0.0}, frc::Rotation2d()));
    _targetPose = frc::Pose2d(units::meter_t{16.4846}, units::meter_t{8.1026}, frc::Rotation2d());

    _hasTarget = _photonResult.HasTargets();

    _hasTargetEntry = frc::Shuffleboard::GetTab("everything").Add("has target", _hasTarget).GetEntry();

}

frc::Pose2d VisionController::GetVisionPose() {
    return photonlib::PhotonUtils::EstimateFieldToRobot(
        CAMERA_HEIGHT_M, TARGET_HEIGHT_M, CAMERA_PITCH_M, units::degree_t{_photonPitch}, frc::Rotation2d(units::degree_t(-_photonYaw)), 
        _navX->GetRotation2d(), _targetPose, _cameraToRobot);
}

void VisionController::Update() {
    _photonResult = _photonVision->GetLatestResult();
    _hasTarget = _photonResult.HasTargets();

    if (_hasTarget) {
        _target = _photonResult.GetBestTarget();
        _photonPose = _target.GetCameraRelativePose();
        _photonPitch = _target.GetPitch();
        _photonYaw = _target.GetYaw();
        _photonDistance = photonlib::PhotonUtils::CalculateDistanceToTarget(
            CAMERA_HEIGHT_M, TARGET_HEIGHT_M, CAMERA_PITCH_M, units::degree_t{_photonPitch}
        );
        _photonCalcPose = GetVisionPose();
    }

    UpdateShuffleboard();
}

void VisionController::UpdateShuffleboard() {
    _hasTargetEntry.SetBoolean(_hasTarget);
    _field->SetRobotPose(_photonCalcPose);

}

VisionController::~VisionController(){}
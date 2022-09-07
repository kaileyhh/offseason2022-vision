#pragma once
#include "PORTS.h"
#include <photonlib/PhotonUtils.h>
#include <photonlib/PhotonCamera.h>
#include <AHRS.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>

#include "networktables/NetworkTable.h"
#include <networktables/NetworkTableEntry.h>
#include "networktables/NetworkTableInstance.h"
#include <frc/smartdashboard/Field2d.h>

class VisionController {
    public:
        VisionController();
        void Update();
        void UpdateShuffleboard();
        frc::Pose2d GetVisionPose();
        ~VisionController();
    private:

        AHRS *_navX; //navX
        double _navXSpeed;

        photonlib::PhotonCamera *_photonVision;
        photonlib::PhotonPipelineResult _photonResult;
        photonlib::PhotonTrackedTarget _target;
        frc::Transform2d _photonPose;
        units::meter_t _photonDistance;
        double _photonPitch;
        double _photonYaw;


        frc::Pose2d _targetPose;
        frc::Transform2d _cameraToRobot;

        frc::Pose2d _photonCalcPose;

        frc::Field2d *_field;
        nt::NetworkTableEntry _fieldEntry;
        nt::NetworkTableEntry _hasTargetEntry;

        bool _hasTarget;
};
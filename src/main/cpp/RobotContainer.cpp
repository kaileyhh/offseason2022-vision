// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h" 
#include <iostream>

RobotContainer::RobotContainer() {
  // _ledController = new LEDController();
  _visionController = new VisionController();
  // printf("Initialized led controller");
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

// Updates sensor states
void RobotContainer::UpdateSensors() {
  _visionController->Update();
  // _ledController->Update(); // This is where the LEDs are updated!
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

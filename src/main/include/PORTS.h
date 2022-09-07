#pragma once

#include <units/acceleration.h>
#include <units/angle.h>
#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>
#include <units/voltage.h>
#include <wpi/numbers>

static const int LED_LENGTH = 3; // change this to light up more or less LEDs! Max: 38

// -- DO NOT CHANGE --
static const int LED_PORT = 7;
static const int LED_SAT = 150;
static const int LED_VAL = 247; 

static const double ACTUAL_TARGET_HEIGHT                 = 104/12.0; //UPDATE
static const double CAMERA_HEIGHT                        = 4.0; //ft
static const double CAMERA_ANGLE                         = 30.0; //degrees tilted up

static const units::meter_t CAMERA_HEIGHT_M              = units::meter_t{1.2192};
static const units::meter_t TARGET_HEIGHT_M              = units::meter_t{2.6416};
static const units::degree_t CAMERA_PITCH_M              = units::degree_t{30};
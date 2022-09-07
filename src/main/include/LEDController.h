
#pragma once
#include "PORTS.h"
#include <frc/AddressableLED.h>

class LEDController {
  public:
    LEDController();
    void Update(); 
    ~LEDController();
  private:
    frc::AddressableLED *_ledStrip;
    std::array<frc::AddressableLED::LEDData, LED_LENGTH> _ledBuffer;
};
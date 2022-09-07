#include "LEDController.h"

// Constructor - creates an LED controller!
LEDController::LEDController() {
    _ledStrip = new frc::AddressableLED(LED_PORT);
    
    for (int i = 0; i < LED_LENGTH; i++) {
        // change the first parameter to change colors :D
        _ledBuffer[i].SetHSV(255, LED_SAT, LED_VAL); // values range from 0 to 255
    }

    _ledStrip->SetLength(LED_LENGTH);
    _ledStrip->SetData(_ledBuffer);
    _ledStrip->Start();
}

// Updates LED state
void LEDController::Update() {
     // change the first parameter to change colors :D
    for (int i = 0; i < LED_LENGTH; i++) {;
        _ledBuffer[i].SetHSV(255, LED_SAT, LED_VAL); // values range from 0 to 255
    }
    _ledStrip->SetData(_ledBuffer);
}

// Destructor
LEDController::~LEDController() {}
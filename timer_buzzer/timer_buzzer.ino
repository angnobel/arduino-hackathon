#include "SevSeg.h"
SevSeg sevseg;

float displayTimeSecs = 1; //how long do you want each number on display to show (in secs)
float displayTime = (displayTimeSecs * 5000);
long buzzerFrequency = 4000;
float buzzerDuration = (displayTimeSecs * 100);
long startNumber = 10; //countdown starts with this number
long endNumber = 0; //countdown ends with this number

const int buzzerPin = 0;
const int buttonPin = A0;
bool state = false;
bool allow = true;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin,OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  
  bool resistorsOnSegments = false;
  byte hardwareConfig = COMMON_CATHODE;
  bool updateWithDelays = false;
  bool leadingZeros = true;
  bool disableDecPoint = true;
  tone(0, 100,4);

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
}

void loop() {
  int buttonSensorVal = digitalRead(buttonPin);
  
  if (state == false) {
    if (buttonSensorVal == 1) {
        tone(buzzerPin,buzzerFrequency,buzzerDuration);
    
      if (startNumber >= endNumber) {
        for (long i = 0; i <= displayTime; i++){
          sevseg.setNumber(startNumber,0);
          sevseg.refreshDisplay();
        } 
      startNumber--;
      tone(buzzerPin,buzzerFrequency,buzzerDuration);    
      }
      if (!allow) {
        allow = true;
      }
    } else if (allow) {
        state = true;
        allow = false;
    }   
      
  } else {
      if (allow) {
          if (buttonSensorVal == 0 && startNumber != 180) {
              startNumber = 180;
              sevseg.setNumber(startNumber,0);
              allow = false;
          } else if (buttonSensorVal == 0 && startNumber == 180) {
              state = false;
              allow = false;
          }
      }
      if (buttonSensorVal == 1 && state) {
          allow = true;
          
      }
  }
  
  
  sevseg.refreshDisplay();
}

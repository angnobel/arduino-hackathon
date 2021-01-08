const int red = 13;
const int yellow = 12;
const int white = 11;
const int black = 10;
const int led = 9;

// Sequence black, red, white, yellow
int testState = 0;
boolean reset = false;
int in = 0;
int out = 1;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  Serial.print("Start");
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(red, INPUT_PULLUP);
  pinMode(yellow, INPUT_PULLUP);
  pinMode(white, INPUT_PULLUP);
  pinMode(black, INPUT_PULLUP);
  pinMode(led, OUTPUT);

}

void blink() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

void solid() {
  digitalWrite(led, HIGH);
}

void loop() {
  // Get connection status
  int redVal = digitalRead(red);
  int yellowVal = digitalRead(yellow);
  int whiteVal = digitalRead(white);
  int blackVal = digitalRead(black);
  
  Serial.println(testState);
//  Serial.println(redVal);
//  Serial.println(yellowVal);
//  Serial.println(whiteVal);
//  Serial.println(blackVal);
    
  if (testState == -1) {
    if (redVal == in && yellowVal == in && whiteVal ==in && blackVal == in) {
      testState = 0;
    } else {
      // Blink
      blink();
    }
  } else if (testState == 0) {
    if (redVal == in && yellowVal == in && whiteVal == in && blackVal == out) {
      testState = 1;
    } else if( !(redVal == in && yellowVal == in && whiteVal ==in && blackVal == in)) {
      testState = -1;
    }
  } else if (testState == 1) {
    if (redVal == out && yellowVal == in && whiteVal == in && blackVal == out) {
      testState = 2;
    } else if( !(redVal == in && yellowVal == in && whiteVal == in && blackVal == out)) {
      testState = -1;
    }
  } else if (testState == 2) {
    if (redVal == out && yellowVal == in && whiteVal == out && blackVal == out) {
      testState = 3;
    } else if( !(redVal == out && yellowVal == in && whiteVal == in && blackVal == out)) {
      testState = -1;
    }
  } else if (testState == 3) {
    if (redVal == out && yellowVal == out && whiteVal == out && blackVal == out) {
      testState = 4;
    } else if( !(redVal == out && yellowVal == in && whiteVal == out && blackVal == out)) {
      testState = -1;
    }
  } else if (testState == 4) {
    // Solid
    solid();
  }
  delay(400);
}

const int white = 13;
const int green = 12;
const int black = 11;
const int yellow = 10;
const int red = 9;

const int red1 = 2;
const int green1 = 3;
const int red2 = 4;
const int green2 = 5;
const int red3 = 6;

// Sequence Y,B,R,G,W
const int first = black;
const int second = green;
const int third = red;
const int fourth = yellow; 
const int fifth = white;

int testState = 0;
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
  pinMode(green, INPUT_PULLUP);
  
  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(red3, OUTPUT);

}

void blink() {
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(red3, HIGH);
  delay(1000);                       // wait for a second
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(red3, LOW);
  delay(1000);                       // wait for a second
}

void flashGreen() {
  digitalWrite(green1, HIGH);
  digitalWrite(green2, HIGH);

  delay(1000);                       // wait for a second
  digitalWrite(green1, LOW);
  digitalWrite(green2, LOW);
  delay(1000); 
}

void loop() {
  // Get connection status
  int firstVal = digitalRead(first);
  int secondVal = digitalRead(second);
  int thirdVal = digitalRead(third);
  int fourthVal = digitalRead(fourth);
  int fifthVal = digitalRead(fifth);
  
  Serial.println(testState);
    
  if (testState == -1) {
    if (firstVal == in && secondVal == in && thirdVal ==in && fourthVal == in && fifthVal == in) {
      testState = 0;
    } else {
      // Blink
      blink();
    }
  } else if (testState == 0) {
    if (firstVal == out && secondVal == in && thirdVal == in && fourthVal == in && fifthVal == in) {
      testState = 1;
    } else if( !(firstVal == in && secondVal == in && thirdVal == in && fourthVal == in && fifthVal == in)) {
      testState = -1;
    }
  } else if (testState == 1) {
    if (firstVal == out && secondVal == out && thirdVal == in && fourthVal == in && fifthVal == in) {
      testState = 2;
    } else if( !(firstVal == out && secondVal == in && thirdVal == in && fourthVal == in && fifthVal == in)) {
      testState = -1;
    }
  } else if (testState == 2) {
    if (firstVal == out && secondVal == out && thirdVal == out && fourthVal == in && fifthVal == in) {
      testState = 3;
    } else if( !(firstVal == out && secondVal == out && thirdVal == in && fourthVal == in && fifthVal == in)) {
      testState = -1;
    }
  } else if (testState == 3) {
    if (firstVal == out && secondVal == out && thirdVal == out && fourthVal == out && fifthVal == in) {
      testState = 4;
    } else if( !(firstVal == out && secondVal == out && thirdVal == out && fourthVal == in && fifthVal == in)) {
      testState = -1;
    }
  } else if (testState == 4) {
    if (firstVal == out && secondVal == out && thirdVal == out && fourthVal == out && fifthVal == out) {
      testState = 5;
    } else if( !(firstVal == out && secondVal == out && thirdVal == out && fourthVal == out && fifthVal == in)) {
      testState = -1;
    }
  } else if (testState == 5) {
    if (firstVal == in && secondVal == in && thirdVal ==in && fourthVal == in && fifthVal == in) {
      testState == 0;
      digitalWrite(green1, LOW);
      digitalWrite(green2, LOW);
    } else {
      flashGreen();
    }
    
  }
  delay(400);
}

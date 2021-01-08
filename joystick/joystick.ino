// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);
}

void loop() {  
  int xValue = analogRead(X_pin);
  int yValue = analogRead(Y_pin);
  
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(xValue);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(yValue);
  Serial.print("\n\n");

  int pos = move(xValue, yValue);
  Serial.println(pos);
  delay(500);
}

int move(int xValue, int yValue) {
  if (xValue > 900) {
    return 2; //right
  }
  else if (xValue == 0) {
    return 4; //left
  }
  else if (yValue > 900) {
    return 3; //down
  }
  else if (yValue == 0) {
    return 1; //up
  }
}

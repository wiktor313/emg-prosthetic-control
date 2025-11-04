#include <Servo.h>

const int emgPin = A0;
const int numReadings = 10;  // for moving average filter
int readings[numReadings];
int readIndex = 0;
int total = 0;
int average = 0;

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);

  // Initialize readings buffer
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }
}

void loop() {
  // Read raw EMG value
  int rawValue = analogRead(emgPin);

  // Moving average filter update
  total -= readings[readIndex];
  readings[readIndex] = rawValue;
  total += readings[readIndex];
  readIndex = (readIndex + 1) % numReadings;
  average = total / numReadings;

  // Map filtered value to servo angle (adjust range if needed)
  int angle = map(constrain(average, 50, 800), 50, 800, 0, 180);

  // Control servo motor
  myServo.write(angle);

  // Send the averaged value to serial port for Biomonitor application
  Serial.println(average);

  delay(10); // small delay for stability
}

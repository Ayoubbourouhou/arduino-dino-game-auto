#include <Servo.h>

Servo myservo;
int sensorPin = A0;
int sensorValue = 0;
int val;

void setup() {
  // Initialize the servo and serial communication
  myservo.attach(2);
  Serial.begin(9600);

  // Set the initial position of the servo
  myservo.write(60);
}

void loop() {
  // Read the sensor value
  sensorValue = analogRead(sensorPin);

  // Check if there is an obstacle (cactus)
  if (sensorValue > 650) {
    // obstacle detected (cactus)
    val = 0;
  } 
  else {
    // no obstacle, move the servo to the default position
    val = 60;
    delay(50); // Add a small delay to stabilize the servo
  }

  // Debug: Print sensor value to the serial monitor
  Serial.println(sensorValue);

  // Set the servo position based on the obstacle detection
  myservo.write(val);
}

#include <Arduino.h>

#include <Servo.h>
Servo servo;

const int trigPin = 9;
const int echoPin = 8;
const int servoPin = 2;
const int maxDistance = 20;
int onState = 0;

void setup() {
  servo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 80 && onState == 0) {
    servo.write(180);
    onState = 1;
//    delay(500);
  } else if (distance > 100 && onState == 1) {
    servo.write(0);
    onState = 0;
    
  }
  delay(500);
}

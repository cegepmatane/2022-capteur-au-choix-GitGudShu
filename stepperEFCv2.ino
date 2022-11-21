#include <Stepper.h>

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

int redpin = 4;
int greenpin = 5;

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
	pinMode(greenpin, OUTPUT);
  pinMode(redpin, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
}

void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

	myStepper.setSpeed(10);
  
  if(distance < 10){
    digitalWrite(greenpin, HIGH);
    digitalWrite(redpin, LOW);
    //myStepper.step(stepsPerRevolution);
  }else{
    digitalWrite(greenpin, LOW);
    digitalWrite(redpin, HIGH);
    //myStepper.step(-stepsPerRevolution);
  }
}
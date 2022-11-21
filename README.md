# Exercice avec deux capteurs aux choix

# 1. Le projet

Un stepper motor tourne dans le sens horaire de manière continue et une led rouge est allumée, lorsque l'on place quelque chose devant le capteur ultrasonique, la led verte s'allume et le stepper motor tourne dans le sens anti-horaire jusqu'à une certaine quantité déterminée de step.

# 2. Composants

- Arduino UNO
- 2 LED (generic) 
- 2 Resistor 220 ohm
- Jumper wires
- Pile de 5V
- Stepper Motor 28BYJ-48
- ULN2003 Driver Board

# 3. Code

Il faudra include la librairie ***Stepper.h***

```cpp

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
```

# 4. Diagrammes fritzing

Les 2 nouveaux composants ont été séparer pour plus de clareté, ***seuls l'arduino UNO et le circuit pour les LED sont en communs.***

## Stepper motor
![alt text](https://github.com/cegepmatane/2022-capteur-au-choix-GitGudShu/blob/main/stepper.jpg)

## Capteur ultrasonique
![alt text](https://github.com/cegepmatane/2022-capteur-au-choix-GitGudShu/blob/main/ultrasonic.jpg)

# 5. Sources

- [stepper motor tuto](https://lastminuteengineers.com/28byj48-stepper-motor-arduino-tutorial/)
- [fonctionnement stepper motor](https://www.youtube.com/watch?v=avrdDZD7qEQ&ab_channel=NikodemBartnik)
- [ultrasonic sensor tuto](https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6)

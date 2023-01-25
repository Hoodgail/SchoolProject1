#include <Servo.h>


int servoPin = 3;    // location of servo motor
int ledPin = 4; // location of led
int buttonPin = 2;  // location of button
int buttonState;     // value of button (pressed or not pressed)
int motorRotation;    // rotation of the motor


Servo hoodgail;


void setup() {


     Serial.begin(9600);  // start serial monitor with refresh rate of 9600


     pinMode(buttonPin, INPUT);  // set buttonPin to INPUT
     pinMode(ledPin, OUTPUT); // set ledPin to OUTPUT


     hoodgail.attach(servoPin);
}


// function to rotate the servo motor
void rotate(int value) {


     hoodgail.write(value);  // send digitalWrite of value to servoPin


}

void loop() {


     buttonState = digitalRead(buttonPin);  // read button state and save to buttonState

     if (buttonState == 1) {  // if button is pressed and motorState is false
      unsigned long startTime = millis();
      int duration = 1000;
      unsigned long endTime = startTime + duration;
      while(millis()<endTime)
      {
        digitalWrite(ledPin, HIGH);
        Serial.println("waiting to extinguish");
      }
          rotate(180);  // rotate motor to 82 degrees
          delay(4000);
          rotate(0);
     }
}





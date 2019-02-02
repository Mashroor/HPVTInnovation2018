#include <LIDARLite.h>
#include <LIDARLite_v3HP.h>

LIDARLite lidar; //initialize a Lidar obj


int bLed = 8;//Ports 8 thru 12 are used for the LEDs
int gLed = 9;
int yLed = 10;
int oLed = 11; 
int rLed = 12;

void setup() {
  pinMode(gLed, OUTPUT); //initialize the sets of LEDs
  pinMode(yLed, OUTPUT);
  pinMode(oLed, OUTPUT);
  pinMode(rLed, OUTPUT);
  pinMode(bLed, OUTPUT);
  

  lidar.begin(0, true); //config to default, I2C to 400Hz
  lidar.configure(0);   //mess with this for other configs lol
  
}

void loop() {
  int dist = lidar.distance(); //take in serial data on each pass

  if (dist < 800) {
    digitalWrite(gLed, HIGH);
    digitalWrite(yLed, LOW);
    digitalWrite(oLed, LOW);
    digitalWrite(rLed, LOW);
    digitalWrite(bLed, LOW);
    if (dist < 600) {
      digitalWrite(yLed, HIGH);
      digitalWrite(oLed, LOW);
      digitalWrite(rLed, LOW);
      digitalWrite(bLed, LOW);
      if (dist < 400) {
        digitalWrite(oLed, HIGH);
        digitalWrite(rLed, LOW);
        digitalWrite(bLed, LOW);
        if (dist < 200) {
          digitalWrite(rLed, HIGH);
          digitalWrite(bLed, LOW);
          if (dist < 100) {
            digitalWrite(bLed, HIGH);
          }
        }
      }
    }
  }
  else {
    digitalWrite(gLed, LOW);
    digitalWrite(yLed, LOW);
    digitalWrite(oLed, LOW);
    digitalWrite(rLed, LOW);
    digitalWrite(bLed, LOW);
  }
  
}

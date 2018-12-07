#include <Wire.h>
#include <LIDARLite.h>

LIDARLite myLidarLite;
int grnLED = 12;
int ylwLED = 11;
int ornLED = 10;
int redLED = 9;

void setup()
{	//start serial comms between during initialization stage
	Serial.begin(115200);
	
	//Initialize Lidar to read during on set up
	myLidarLite.begin(0, true); //goes through I2C

	//initialize to default rage, but high speed at short ranges
	mylidarLite.configure(2);
	

	//initialize all LED ports as outputs
	pinMode(grnLED, OUTPUT);
	pinMode(ylwLED, OUTPUT);
	pinMode(ornLED, OUTPUT);
	pinMode(redLED, OUTPUT);

}

void loop()
{
	while(true){
		if(myLidarLite.distance() < 609.6){
			digitalWrite(grnLED, HIGH);
			delay(1000);
			if(myLidarLite.distance() < 518/16){
				digitalWrite(ylwLED, HIGH);
				delay(1000);
				if(myLidarLite.distance < 365.706){
					digitalWrite(rngLED, HIGH);
					delay(1000);
					if(myLidarLite.distance() < 152.4){
						//blink LED here, write method
					}

				}
			}
		}
		else{
			digitalWrite(grnLED, LOW);
			digitalWrite(ylwLED, LOW);
			digitalWrite(ornLED, LOW);
			digitalWrite(redLED, LOW);
		}
	}
}

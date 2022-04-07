

#include <Servo.h>
Servo myservo;

const int trigPin = 13;
const int echoPin = 12;


long duration;
int FirstDistance=0;
int SecondDistance=0;
//int FirstSpeed =0;
//int SecondSpeed=0;
double speed=0;
//double acceleration = 0;
int distance=1;
float Time = 2.0;
float delayedtime = 1000*Time;

float GetDistance()
{
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Set the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

//calculating distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance in cm : ");
Serial.println(distance);

return distance;

}
void GetSpeed(){
 
   FirstDistance = GetDistance(); //get the first distance
   
   delay(delayedtime); //waits 2 seconds depending on the time declared above ,, feel free to change the value dependng on the resolution of your sensor 
   
   SecondDistance = GetDistance(); //gets the second distance
   
   speed = (FirstDistance - SecondDistance)/Time;  // now calculating the difference 
   
 
//printing the speed on the serial monitor
  Serial.print("the speed (cm/s) is  :  ");
  Serial.println(speed);
 
}

//void GetAcceleration(){
//  FirstSpeed = GetSpeed();
//  delay(delayedtime);
//  SecondSpeed = GetSpeed();
//  acceleration = (FirstSpeed-SecondSpeed)/Time;
//}

void setup() {
  myservo.attach(9);
  myservo.write(10); 
//  delay(50000);    
//  myservo.detach(); 
    
  // nothing to do inside the setup
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  
  
}

void loop() {
  // read the sensor value:
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  GetSpeed();
  }

  
  

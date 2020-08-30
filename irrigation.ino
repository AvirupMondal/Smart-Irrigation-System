#define BLYNK_PRINT Serial
int a;
int trigPin = D1;
int echoPin = D2;
int motorPin = D0;

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
charauth[] = "Your Auth Id";
charssid[] = "Name of Your Hotspot Device";
char pass[] = "Password of Hotspot Device";
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
pinMode(A0,INPUT);
pinMode(motorPin,OUTPUT);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(buzzer,OUTPUT);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(buzzer,LOW);
}
voidmotorState(int state)
{
digitalWrite(motorPin,state);
}
void loop()
{
Blynk.run();
  a=analogRead(A0);
Blynk.virtualWrite(V1,a);
if(a>=400)
{
motorState(400);
digitalWrite(motorPin,LOW);  
Serial.println("Watering The Plants");
Serial.println(a);
}
else
{
motorState(1000);
digitalWrite(motorPin,HIGH);
Serial.println("Water Flow Stopped");
Serial.println(a);
}
delay(400); 
digitalWrite(trigPin,LOW);
delay(200);
digitalWrite(trigPin,HIGH);
delay(200);
digitalWrite(trigPin,LOW);
int duration=pulseIn(echoPin,HIGH);
int distance=duration*0.034/2;
if(distance<=10)
    {
digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
Serial.print("The tank is full");
Serial.println(distance);
digitalWrite(buzzer,HIGH);
    }
else if(distance>=50)
    {
digitalWrite(led1,LOW);
digitalWrite(led2,HIGH);
Serial.print("WARNING");
Serial.println(distance);
digitalWrite(buzzer,HIGH);
    }
else
 {
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(buzzer,LOW);
Serial.print("water level at: ");
Serial.println(distance);
    }
Blynk.virtualWrite(V2,distance);
}














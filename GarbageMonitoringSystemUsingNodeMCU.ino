// Blynk.App Quick Start
/*************************************************************
  This example shows how to use Arduino Ethernet shield (W5100)
  to connect your project to Blynk.

  NOTE: Pins 10, 11, 12 and 13 are reserved for Ethernet module.
        DON'T use them in your sketch directly!

  WARNING: If you have an SD card, you may need to disable it
        by setting pin 4 to HIGH. Read more here:
        https://www.arduino.cc/en/Main/ArduinoEthernetShield

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here
#define BLYNK_AUTH_TOKEN "koLiOSQIZEYPFo0OzPe79FKdwFvDa6KB" */
#define BLYNK_TEMPLATE_ID "TMPL3OlJGUe9U"
#define BLYNK_TEMPLATE_NAME "Garbage Monitoring Notification"
#define BLYNK_AUTH_TOKEN "fLRlDzJ32GuicVdtu-W5kA30liJvk62a"
#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
const char Wname[]="RealMe GT Neo 3T"; //SSID
const char pass[]="00000000"; //Password
const char token[]="fLRlDzJ32GuicVdtu-W5kA30liJvk62a"; // Auth Token
const int trigPin = 12; // D6
const int echoPin = 14; // D5
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  Blynk.begin(token, Wname, pass);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Set the trigger pin high for 10us
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance (in cm)
  distance = duration * 0.034 / 2;
  if(distance<5)
    Blynk.logEvent("Dustbin is almost full.");
  // Print the distance to the Serial Monitor
  Blynk.virtualWrite(V2, distance);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  // Wait for a short time before taking the next measurement
  delay(5000);
  Blynk.run();
}
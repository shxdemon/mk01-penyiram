#include <Wire.h>
#include <MoistureSensor.h>
#include <Servo.h>
Servo servo1;
Servo servo2;

int SensorCahaya = A0;
int SensorTanah = A1;
int RelayPompa = 3;
int BasahLED = 4;
int KeringLED = 5;
int LembabLED = 6;
 
// you can adjust the threshold value
int basah = 450;
int kering = 800;

void setup(){
  pinMode(SensorCahaya, INPUT);
  pinMode(SensorTanah, INPUT);
  pinMode(BasahLED, OUTPUT);
  pinMode(KeringLED, OUTPUT);
  pinMode(LembabLED, OUTPUT);
  pinMode(RelayPompa, OUTPUT);
  digitalWrite(BasahLED, LOW);
  digitalWrite(KeringLED, LOW);
  digitalWrite(LembabLED, LOW);
  digitalWrite(RelayPompa, LOW);
  Serial.begin(9600);
    //Setting Servo 1
  servo1.attach(8);
  servo1.write(90);
    //Setting Servo 2
  servo2.attach(9);
  servo2.write(180);
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(SensorTanah);
  Serial.print(sensorValue);
  if(sensorValue < basah){
    Serial.println(" - Tanah Basah");
    digitalWrite(KeringLED, LOW);
    digitalWrite(BasahLED, HIGH);
    digitalWrite(RelayPompa, LOW);
    digitalWrite(LembabLED, LOW);
    delay(1000);
  }
  else if(sensorValue > kering) {
    Serial.println(" - Tanah Kering");
    digitalWrite(RelayPompa, HIGH);
    digitalWrite(KeringLED, HIGH);
    digitalWrite(BasahLED, LOW);
    digitalWrite(LembabLED, LOW);
    delay(1000);
  }
  else if(sensorValue > basah || sensorValue < kering ){
    Serial.println(" - Tanah Lembab");
    digitalWrite(KeringLED, LOW);
    digitalWrite(BasahLED, LOW);
    digitalWrite(LembabLED, HIGH);
    digitalWrite(RelayPompa, LOW);
    delay(1000);
    }

    //MembacaPhotodioda
    int cahayaValue = analogRead(SensorCahaya);
    Serial.print("Intensitas Cahaya = ");
    Serial.println(cahayaValue);
    delay(800);
    if(cahayaValue > 800){
      servo1.write(
        
        180);
      servo2.write(90);
      delay(8);
      }
     else if(cahayaValue < 250){
      servo1.write(90);
      servo2.write(180);
      delay(8);
      }
}

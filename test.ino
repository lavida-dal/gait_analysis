#include <SoftwareSerial.h>
#define bluetoothTx 2
#define bluetoothRx 3

int led1 = 7;
int led2 = 6;

int RX=2;
int TX=3;
SoftwareSerial bluetooth(RX, TX);
 
void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}
 
void loop(){
// digitalWrite(led2,HIGH);
int ledStatus1 = digitalRead(led1);
  if (ledStatus1 == LOW) {
    digitalWrite(led2, HIGH);
  }
  if (ledStatus1 == HIGH) {
    digitalWrite(led2, LOW);
  }
  if (bluetooth.available()) {
    Serial.write(bluetooth.read());
  }
  if (Serial.available()) {
    bluetooth.write(Serial.read());
  }
 char num = (char)bluetooth.read();
 int num2 = Serial.read();
 
      if(num2 == '1') {
       digitalWrite(led2,LOW);
       delay(1000);
       digitalWrite(led1,HIGH);
       delay(5000);
       digitalWrite(led1,LOW);
      }
      if(num2 == '2') {
        digitalWrite(led2,HIGH);
        digitalWrite(led1,LOW);
      }
}

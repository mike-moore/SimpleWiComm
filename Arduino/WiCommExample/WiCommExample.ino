#include <SoftwareSerial.h>
 
SoftwareSerial mySerial =  SoftwareSerial(2, 3);
 
 
void setup()  {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
}
 
 
 
void loop()                     // run over and over again
{
 
  if (mySerial.available()) {
      Serial.print((char)mySerial.read());
  }
  if (Serial.available()) {
      mySerial.print((char)Serial.read());
  }
  delay(100);
}

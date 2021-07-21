#include <SPI.h>
#include <MFRC522.h>
#include "SoftwareSerial.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
SoftwareSerial ser(2,3); // RX, TX 
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  ser.begin (115200);
  
  //lcd.begin();
  
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your RFID Card to reader...");
 
  lcd.init();                      
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
   
  lcd.print("Scan your card");
 
}


void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("User ID : ");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("User No- User  Name : ");
  content.toUpperCase();
   
  if (content.substring(1) == "99 6E 6A B9" ){
    Serial.println("1- Sanjila Shrestha");
    Serial.println("Message : Attendance Successfull..");
    ser.write(1);
    Serial.println();
    lcd.clear();

    lcd.setCursor(1,0);
    lcd.print("Attendance Sucessfull");

    delay(3000);

    lcd.clear();
    lcd.print("Scan your card");

  }
  if (content.substring(1) ==  "15 EE 59 32" ) {
    Serial.println("2- Mahima Shrestha");
    Serial.println("Message : Attendance Successfull..");
    ser.write(2);
    Serial.println();
    
    lcd.clear();
    lcd.print("Attendance Sucessfull..");
    
    delay(3000);

    lcd.clear();
    lcd.print("Scan your card");
  }
   if (content.substring(1) == "43 09 4C 63" ) 
  {
    Serial.println("3- Rajeesha Shrestha");
    Serial.println("Message : Attendance Successfull..");
    ser.write(3);
    Serial.println();
    lcd.clear();
    lcd.print("Attendance Sucessfull..");
    
    delay(3000);

    lcd.clear();
    lcd.print("Scan your card");
  }
   if (content.substring(1) == "09 AE 64 40" )
  {
    Serial.println("4- Rajiv Sunar");
    Serial.println("Message : Attendance Successfull..");
    ser.write(4);
    Serial.println();
    lcd.clear();
    lcd.print("Attendance Sucessfull..");
    
    delay(3000);

    lcd.clear();
    lcd.print("Scan your card");
  }
   if (content.substring(1) == "69 CD 5A 98" ) 
  {
    Serial.println("5- Shristi Shrestha");
    Serial.println("Message : Attendance Successfull..");
    ser.write(5);
    Serial.println();
    
    lcd.clear();
    lcd.print("Attendance Sucessfull..");
    
    delay(3000);

    lcd.clear();
    lcd.print("Scan your card");
  }
    if (content.substring(1) ==  "B9 5E 43 B8" )
  {
    Serial.println("6- Rajiv Karki");
    Serial.println("Message : Attendance Sucessfull..");
    ser.write(6);
    Serial.println();
    lcd.clear();
    lcd.print("Attendance Sucessfull..");
    
    delay(3000);

    lcd.clear();
    lcd.print("Scan your card");
  }
}
  

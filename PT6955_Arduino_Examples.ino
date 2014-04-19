

/*
PT6955
 
 DIN (MOSI) - Data Input Pin
 This pin inputs serial data at the rising edge of the
 shift clock (starting from the lower bit)
 
 CLK - Clock Input Pin
 This pin reads serial data at the rising edge.
 
 STB (SS) - Serial Interface Strobe Pin
 The data input after the STB has fallen is processed
 as a command. When this pin is "HIGH", CLK is ignored.
 
 SPI SPI_MODE3
 
 CPOL=1 the base value of the clock is one
 CPHA=1, data are captured on clock's rising edge
 
 MSB First
 
 Arduino Pinout
 
 Arduino Board	      MOSI	      MISO      	SCK	      SS (slave)
 Uno or Duemilanove    11 or ICSP-4    -          	13 or ICSP-3  10
 
 */

#include <SPI.h>                            //  Links prewritten SPI library into the code
#include "PT6955_Arduino.h"
#define countdelayms 10

void setup()
{
  Serial.begin(9600);

  pinMode(2, INPUT);                     //  Set pins 2-9 as inputs
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, OUTPUT);                //  Set SPI pins to be outputs
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(2, HIGH);                   //  Set Arduino pull-up resistors active
  digitalWrite(3, HIGH);                   //  This sets an internal to the chip
  digitalWrite(4, HIGH);                   //  pull-up resistor on so an unconnected pin
  digitalWrite(5, HIGH);                   //  is reliably at logic 1
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(13, HIGH);

  initializeDisplay();

}

void loop()
{

  int month = 12;
  int day = 31;
  int counter = -1;

  while(1){
    while(counter == -1){
    delay(countdelayms);
      byte LEDMatrix [8] = {
        0,0,0,0,0,0,0,0      };
      writecolon(LEDMatrix);  
      writedigit1(LEDMatrix, month/10);  // months 10's place
      writedigit2(LEDMatrix, month%10);  // months 1's place
      writedigit3(LEDMatrix, day/10);  // days 10's place
      writedigit4(LEDMatrix, day%10);  // days 1's place

      updateLED(LEDMatrix);

      if(day > 0){
        day = day + counter; 
      }
      else {
        day = 31;
        if (month > 0){
          month = month + counter;
        }
        else{
          //month = 12;
          day = 0;
          month = 0;
          counter = 1;
        }
      } 
    }// while

    while(counter == 1){
      delay(countdelayms);
      byte LEDMatrix [8] = {
        0,0,0,0,0,0,0,0      };
      writecolon(LEDMatrix);

      writedigit1(LEDMatrix, month/10);  // months 10's place
      writedigit2(LEDMatrix, month%10);  // months 1's place
      writedigit3(LEDMatrix, day/10);  // days 10's place
      writedigit4(LEDMatrix, day%10);  // days 1's place

      updateLED(LEDMatrix);

      if(day < 32){
        day = day + counter; 
      }
      else {
        day = 0;
        if (month < 12){
          month = month + counter;
        }
        else{
          //month = 12;
          day = 31;
          counter = -1;
        }
      } 
    }// while  

  } // while(1)  

}

void updateLED(byte LEDMatrix[]){


  digitalWrite(10,LOW);                
  SPI.transfer(B01000000);             //COMMAND 2: DATA SETTING COMMANDS
  digitalWrite(10,HIGH);
  //delay(10);

  digitalWrite(10,LOW);                //  Drop SPI chip-select to 0 (Arduino pin 10)
  SPI.transfer(B11000000);             //COMMAND 3: ADDRESS SETTING COMMANDS
  for (int i = 0; i<8; i++){
    SPI.transfer(LEDMatrix[i]);             //CDATA
  }

  digitalWrite(10,HIGH);               

}

void clearLED(){
  byte LEDMatrix [8] = {
    0,0,0,0,0,0,0,0  }; 
  updateLED(LEDMatrix);

}


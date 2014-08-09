

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

#include <SPI.h>          //  Links prewritten SPI library into the code
#include "PT6955_Arduino.h"
#include <DS3232RTC.h>    //http://github.com/JChristensen/DS3232RTC
#include <Time.h>         //http://www.arduino.cc/playground/Code/Time  
#include <Wire.h>         //http://arduino.cc/en/Reference/Wire (included with Arduino IDE)

#define countdelayms 200

volatile int displayon = false;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);   //  D2 - pin for interrupt 0
  pinMode(10, OUTPUT); //  Set SPI pins to be outputs
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);

  initializeDisplay();
  attachInterrupt(0, displayToggle, CHANGE);

  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if(timeStatus() != timeSet) 
    Serial.println("Unable to sync with the RTC");
  else
    Serial.println("RTC has set the system time");  
}

void loop()
{
  byte LEDMatrix [8] = {
    0,0,0,0,0,0,0,0      };

  if (displayon){

    // display time
    int colonstate = true;  // for flashing colon for time display
    for(int i = 0; i<6; i++){
      clearMatrix(LEDMatrix);  
      if (isAM()) writeam(LEDMatrix); 
      else writepm(LEDMatrix);
      if (colonstate) writecolon(LEDMatrix);
      writedigit1(LEDMatrix, hourFormat12()/10);  // 10's place
      writedigit2(LEDMatrix, hourFormat12()%10);  // 1's place
      writedigit3(LEDMatrix, minute()/10);  // 10's place
      writedigit4(LEDMatrix, minute()%10);  // 10's place
      writedigit5(LEDMatrix, month()/10);  // 1's place
      updateLED(LEDMatrix);
      colonstate = !colonstate;
      delay(1000);
    }
    
    // display date    
    clearMatrix(LEDMatrix); 
    writedigit1(LEDMatrix, month()/10);  // 10's place
    writedigit2(LEDMatrix, month()%10);  // 1's place
    if (day()/10 > 0)
      writedigit3(LEDMatrix, day()/10);  // 10's place
    writedigit4(LEDMatrix, day()%10);  // 1's place
    updateLED(LEDMatrix);
    delay(5000);

    // display year    
    clearMatrix(LEDMatrix); 
    writedigit2(LEDMatrix, year()/1000 %10);  // 1000's place
    writedigit3(LEDMatrix, year()/100 %10);  // 100's place
    writedigit4(LEDMatrix, year()/10 %10);  // 10's place
    writedigit6(LEDMatrix, year()%10);  // 1's place
    updateLED(LEDMatrix);
    delay(5000);

      
}
  else{ 
    clearLED();
  }
  displayon = false;
  delay(10);
}// loop ()


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
    0,0,0,0,0,0,0,0                  }; 
  digitalWrite(10,LOW);                
  SPI.transfer(B01000000);             //COMMAND 2: DATA SETTING COMMANDS
  digitalWrite(10,HIGH);
  //delay(10);

  digitalWrite(10,LOW);                //  Set SPI chip-select to 0 (Arduino pin 10)
  SPI.transfer(B11000000);             //COMMAND 3: ADDRESS SETTING COMMANDS
  for (int i = 0; i<8; i++){
    SPI.transfer(LEDMatrix[i]);        //CDATA
  }

  digitalWrite(10,HIGH);

}

void displayToggle()
{
  if (digitalRead(2)){
    displayon = digitalRead(2);
  }  
}

void clearMatrix(byte LEDMatrix[]){
  for (int i = 0; i<8; i++){
    LEDMatrix[i] = 0;
  }
}

int daysToChristmas(){
  
  
}



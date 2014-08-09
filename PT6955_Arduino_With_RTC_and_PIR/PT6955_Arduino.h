#ifndef PT6955_ARDUINO_H
#define PT6955_ARDUINO_H

  // display setup

void initializeDisplay(){ 
 
  SPI.begin();                             //  Initialize SPI parameters
  SPI.setBitOrder(LSBFIRST);               //  Least significant byte to be sent first
  SPI.setDataMode(SPI_MODE3);              //  Set for clock rising edge
  SPI.setClockDivider(SPI_CLOCK_DIV64);    //  Set clock divider (optional)
  delay(200);
  
  digitalWrite(10,LOW);                
  SPI.transfer(B01000000);             //COMMAND 2: DATA SETTING COMMANDS
  digitalWrite(10,HIGH); 
  
  digitalWrite(10,LOW);                
  SPI.transfer(B11000000);             //COMMAND 3: ADDRESS SETTING COMMANDS
  digitalWrite(10,HIGH);
 
  digitalWrite(10,LOW);                
  SPI.transfer(B00000000);             //COMMAND 1: DISPLAY MODE SETTING COMMANDS  - 00: 4 digits, 12 segments
  digitalWrite(10,HIGH);                
  
  digitalWrite(10,LOW);                
  SPI.transfer(B10001011);             //COMMAND 4: DISPLAY CONTROL COMMANDS
  digitalWrite(10,HIGH); 
}

// 1 or blank only
void writedigit1(byte LEDMatrix[], int newNum){
   switch ( newNum ) {
    case 1:
    LEDMatrix[1] = LEDMatrix[1] | 8; 
    LEDMatrix[3] = LEDMatrix[3] | 8;  
    break;     
   }
}
void writedigit2_0(byte LEDMatrix[]){
 LEDMatrix[1] = LEDMatrix[1] | 1; 
 LEDMatrix[2] = LEDMatrix[2] | 128; 
 LEDMatrix[3] = LEDMatrix[3] | 1; 
 LEDMatrix[5] = LEDMatrix[5] | 1; 
 LEDMatrix[7] = LEDMatrix[7] | 1; 
 LEDMatrix[6] = LEDMatrix[6] | 128; 
}

void writedigit2_1(byte LEDMatrix[]){
 LEDMatrix[2] = LEDMatrix[2] | 128; 
 LEDMatrix[6] = LEDMatrix[6] | 128; 
}

void writedigit2_2(byte LEDMatrix[]){
 LEDMatrix[1] = LEDMatrix[1] | 1;
 LEDMatrix[2] = LEDMatrix[2] | 128;
 LEDMatrix[4] = LEDMatrix[4] | 128;
 LEDMatrix[5] = LEDMatrix[5] | 1;
 LEDMatrix[7] = LEDMatrix[7] | 1;
}

void writedigit2_3(byte LEDMatrix[]){
 LEDMatrix[1] = LEDMatrix[1] | 1;
 LEDMatrix[2] = LEDMatrix[2] | 128;
 LEDMatrix[4] = LEDMatrix[4] | 128;
 LEDMatrix[6] = LEDMatrix[6] | 128;
 LEDMatrix[7] = LEDMatrix[7] | 1;
}

void writedigit2_4(byte LEDMatrix[]){
 LEDMatrix[3] = LEDMatrix[3] | 1;
 LEDMatrix[2] = LEDMatrix[2] | 128;
 LEDMatrix[4] = LEDMatrix[4] | 128;
 LEDMatrix[6] = LEDMatrix[6] | 128;
}

void writedigit2_5(byte LEDMatrix[]){
 LEDMatrix[1] = LEDMatrix[1] | 1;
 LEDMatrix[3] = LEDMatrix[3] | 1;
 LEDMatrix[4] = LEDMatrix[4] | 128;
 LEDMatrix[6] = LEDMatrix[6] | 128;
 LEDMatrix[7] = LEDMatrix[7] | 1;
}

void writedigit2_6(byte LEDMatrix[]){
 LEDMatrix[3] = LEDMatrix[3] | 1;
 LEDMatrix[5] = LEDMatrix[5] | 1;
 LEDMatrix[4] = LEDMatrix[4] | 128;
 LEDMatrix[6] = LEDMatrix[6] | 128;
 LEDMatrix[7] = LEDMatrix[7] | 1;
}

void writedigit2_7(byte LEDMatrix[]){
 LEDMatrix[1] = LEDMatrix[1] | 1;
 LEDMatrix[2] = LEDMatrix[2] | 128;
 LEDMatrix[6] = LEDMatrix[6] | 128;
 }

void writedigit2_8(byte LEDMatrix[]){
 LEDMatrix[1] = LEDMatrix[1] | 1;
 LEDMatrix[2] = LEDMatrix[2] | 128;
 LEDMatrix[4] = LEDMatrix[4] | 128;
 LEDMatrix[5] = LEDMatrix[5] | 1;
 LEDMatrix[7] = LEDMatrix[7] | 1;
 LEDMatrix[3] = LEDMatrix[3] | 1;
 LEDMatrix[6] = LEDMatrix[6] | 128;
}

void writedigit2_9(byte LEDMatrix[]){
 LEDMatrix[1] = LEDMatrix[1] | 1;
 LEDMatrix[2] = LEDMatrix[2] | 128;
 LEDMatrix[4] = LEDMatrix[4] | 128;
 LEDMatrix[3] = LEDMatrix[3] | 1;
 LEDMatrix[6] = LEDMatrix[6] | 128;
}

void writedigit2(byte LEDMatrix[], int newNum){
   switch ( newNum ) {
    case 0:
    writedigit2_0(LEDMatrix);   
    break; 
    case 1:
    writedigit2_1(LEDMatrix);   
    break;     
    case 2:
    writedigit2_2(LEDMatrix);   
    break;     
    case 3:
    writedigit2_3(LEDMatrix);   
    break;     
    case 4:
    writedigit2_4(LEDMatrix);   
    break;     
    case 5:
    writedigit2_5(LEDMatrix);   
    break;
    case 6:
    writedigit2_6(LEDMatrix);   
    break; 
    case 7:
    writedigit2_7(LEDMatrix);   
    break; 
    case 8:
    writedigit2_8(LEDMatrix);   
    break; 
    case 9:
    writedigit2_9(LEDMatrix);   
    break;     
  }
 
}

void writedigit3_0(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 64;
 LEDMatrix[2] = LEDMatrix[2] | 32;
 LEDMatrix[2] = LEDMatrix[2] | 64;  
 LEDMatrix[4] = LEDMatrix[4] | 64;
 LEDMatrix[6] = LEDMatrix[6] | 32;
 LEDMatrix[6] = LEDMatrix[6] | 64; 
}

void writedigit3_1(byte LEDMatrix[]){
 LEDMatrix[2] = LEDMatrix[2] | 32;
 LEDMatrix[6] = LEDMatrix[6] | 32;
}

void writedigit3_2(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 64;
 LEDMatrix[2] = LEDMatrix[2] | 32; 
 LEDMatrix[4] = LEDMatrix[4] | 32; 
 LEDMatrix[4] = LEDMatrix[4] | 64;
 LEDMatrix[6] = LEDMatrix[6] | 64; 
}

void writedigit3_3(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 64;
 LEDMatrix[2] = LEDMatrix[2] | 32; 
 LEDMatrix[4] = LEDMatrix[4] | 32; 
 LEDMatrix[6] = LEDMatrix[6] | 32;
 LEDMatrix[6] = LEDMatrix[6] | 64; 
}

void writedigit3_4(byte LEDMatrix[]){
 LEDMatrix[2] = LEDMatrix[2] | 32;
 LEDMatrix[2] = LEDMatrix[2] | 64; 
 LEDMatrix[4] = LEDMatrix[4] | 32; 
 LEDMatrix[6] = LEDMatrix[6] | 32;
}

void writedigit3_5(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 64;
 LEDMatrix[2] = LEDMatrix[2] | 64; 
 LEDMatrix[4] = LEDMatrix[4] | 32; 
 LEDMatrix[6] = LEDMatrix[6] | 32;
 LEDMatrix[6] = LEDMatrix[6] | 64; 
}

void writedigit3_6(byte LEDMatrix[]){
 LEDMatrix[2] = LEDMatrix[2] | 64; 
 LEDMatrix[4] = LEDMatrix[4] | 32; 
 LEDMatrix[4] = LEDMatrix[4] | 64;
 LEDMatrix[6] = LEDMatrix[6] | 32;
 LEDMatrix[6] = LEDMatrix[6] | 64; 
}

void writedigit3_7(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 64;
 LEDMatrix[2] = LEDMatrix[2] | 32;
 LEDMatrix[6] = LEDMatrix[6] | 32;
}

void writedigit3_8(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 64;
 LEDMatrix[2] = LEDMatrix[2] | 32;
 LEDMatrix[2] = LEDMatrix[2] | 64; 
 LEDMatrix[4] = LEDMatrix[4] | 32; 
 LEDMatrix[4] = LEDMatrix[4] | 64;
 LEDMatrix[6] = LEDMatrix[6] | 32;
 LEDMatrix[6] = LEDMatrix[6] | 64; 
}

void writedigit3_9(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 64;
 LEDMatrix[2] = LEDMatrix[2] | 32;
 LEDMatrix[2] = LEDMatrix[2] | 64; 
 LEDMatrix[4] = LEDMatrix[4] | 32; 
 LEDMatrix[6] = LEDMatrix[6] | 32; 
}

void writedigit3(byte LEDMatrix[], int newNum){
   switch ( newNum ) {
    case 0:
    writedigit3_0(LEDMatrix);   
    break; 
    case 1:
    writedigit3_1(LEDMatrix);   
    break;     
    case 2:
    writedigit3_2(LEDMatrix);   
    break;     
    case 3:
    writedigit3_3(LEDMatrix);   
    break;     
    case 4:
    writedigit3_4(LEDMatrix);   
    break;     
    case 5:
    writedigit3_5(LEDMatrix);   
    break;
    case 6:
    writedigit3_6(LEDMatrix);   
    break; 
    case 7:
    writedigit3_7(LEDMatrix);   
    break; 
    case 8:
    writedigit3_8(LEDMatrix);   
    break; 
    case 9:
    writedigit3_9(LEDMatrix);   
    break;     
  }
 
}


void writedigit4_0(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 16;
 LEDMatrix[2] = LEDMatrix[2] | 8;
 LEDMatrix[2] = LEDMatrix[2] | 16;
 LEDMatrix[6] = LEDMatrix[6] | 8;
 LEDMatrix[4] = LEDMatrix[4] | 16; 
 LEDMatrix[6] = LEDMatrix[6] | 8; 
 LEDMatrix[6] = LEDMatrix[6] | 16; 
}

void writedigit4_1(byte LEDMatrix[]){
 LEDMatrix[2] = LEDMatrix[2] | 8; 
 LEDMatrix[6] = LEDMatrix[6] | 8; 
}

void writedigit4_2(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 16;
 LEDMatrix[2] = LEDMatrix[2] | 8;
 LEDMatrix[4] = LEDMatrix[4] | 8;
 LEDMatrix[4] = LEDMatrix[4] | 16; 
 LEDMatrix[6] = LEDMatrix[6] | 16; 
}

void writedigit4_3(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 16;
 LEDMatrix[2] = LEDMatrix[2] | 8;
 LEDMatrix[4] = LEDMatrix[4] | 8;
 LEDMatrix[6] = LEDMatrix[6] | 8;
 LEDMatrix[6] = LEDMatrix[6] | 8; 
 LEDMatrix[6] = LEDMatrix[6] | 16; 
}

void writedigit4_4(byte LEDMatrix[]){
 LEDMatrix[2] = LEDMatrix[2] | 8;
 LEDMatrix[2] = LEDMatrix[2] | 16;
 LEDMatrix[4] = LEDMatrix[4] | 8;
 LEDMatrix[6] = LEDMatrix[6] | 8;
 LEDMatrix[6] = LEDMatrix[6] | 8;  
}

void writedigit4_5(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 16;
 LEDMatrix[2] = LEDMatrix[2] | 16;
 LEDMatrix[4] = LEDMatrix[4] | 8;
 LEDMatrix[6] = LEDMatrix[6] | 8; 
 LEDMatrix[6] = LEDMatrix[6] | 8; 
 LEDMatrix[6] = LEDMatrix[6] | 16; 
}

void writedigit4_6(byte LEDMatrix[]){
 LEDMatrix[2] = LEDMatrix[2] | 16;
 LEDMatrix[4] = LEDMatrix[4] | 8;
 LEDMatrix[6] = LEDMatrix[6] | 8;
 LEDMatrix[4] = LEDMatrix[4] | 16; 
 LEDMatrix[6] = LEDMatrix[6] | 8; 
 LEDMatrix[6] = LEDMatrix[6] | 16; 
}

void writedigit4_7(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 16;
 LEDMatrix[2] = LEDMatrix[2] | 8;
 LEDMatrix[6] = LEDMatrix[6] | 8; 
 LEDMatrix[6] = LEDMatrix[6] | 8; 
}

void writedigit4_8(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 16;
 LEDMatrix[2] = LEDMatrix[2] | 8;
 LEDMatrix[2] = LEDMatrix[2] | 16;
 LEDMatrix[4] = LEDMatrix[4] | 8;
 LEDMatrix[6] = LEDMatrix[6] | 8;
 LEDMatrix[4] = LEDMatrix[4] | 16; 
 LEDMatrix[6] = LEDMatrix[6] | 8; 
 LEDMatrix[6] = LEDMatrix[6] | 16; 
}

void writedigit4_9(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 16;
 LEDMatrix[2] = LEDMatrix[2] | 8;
 LEDMatrix[2] = LEDMatrix[2] | 16;
 LEDMatrix[4] = LEDMatrix[4] | 8;
 LEDMatrix[6] = LEDMatrix[6] | 8;
 LEDMatrix[6] = LEDMatrix[6] | 8; 
}

void writedigit4(byte LEDMatrix[], int newNum){
   switch ( newNum ) {
    case 0:
    writedigit4_0(LEDMatrix);   
    break; 
    case 1:
    writedigit4_1(LEDMatrix);   
    break;     
    case 2:
    writedigit4_2(LEDMatrix);   
    break;     
    case 3:
    writedigit4_3(LEDMatrix);   
    break;     
    case 4:
    writedigit4_4(LEDMatrix);   
    break;     
    case 5:
    writedigit4_5(LEDMatrix);   
    break;
    case 6:
    writedigit4_6(LEDMatrix);   
    break; 
    case 7:
    writedigit4_7(LEDMatrix);   
    break; 
    case 8:
    writedigit4_8(LEDMatrix);   
    break; 
    case 9:
    writedigit4_9(LEDMatrix);   
    break;     
  }
 
}


// 1 or blank only
void writedigit5(byte LEDMatrix[], int newNum){
   switch ( newNum ) {
    case 1:
    LEDMatrix[0] = LEDMatrix[0] | 2;  
    break;     
   }
}

void writedigit6_0(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 4; 
 LEDMatrix[2] = LEDMatrix[2] | 4; 
 LEDMatrix[2] = LEDMatrix[2] | 2;
 LEDMatrix[4] = LEDMatrix[4] | 4;
 LEDMatrix[6] = LEDMatrix[6] | 2;
 LEDMatrix[6] = LEDMatrix[6] | 4;
}

void writedigit6_1(byte LEDMatrix[]){
 LEDMatrix[2] = LEDMatrix[2] | 2; 
 LEDMatrix[6] = LEDMatrix[6] | 2; 
}

void writedigit6_2(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 4; 
 LEDMatrix[2] = LEDMatrix[2] | 2;
 LEDMatrix[4] = LEDMatrix[4] | 2;
 LEDMatrix[4] = LEDMatrix[4] | 4;
 LEDMatrix[6] = LEDMatrix[6] | 4;
}

void writedigit6_3(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 4; 
 LEDMatrix[2] = LEDMatrix[2] | 2;
 LEDMatrix[4] = LEDMatrix[4] | 2;
 LEDMatrix[6] = LEDMatrix[6] | 2;
 LEDMatrix[6] = LEDMatrix[6] | 4;
}

void writedigit6_4(byte LEDMatrix[]){
 LEDMatrix[2] = LEDMatrix[2] | 4; 
 LEDMatrix[2] = LEDMatrix[2] | 2;
 LEDMatrix[4] = LEDMatrix[4] | 2;
 LEDMatrix[6] = LEDMatrix[6] | 2;
}

void writedigit6_5(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 4; 
 LEDMatrix[2] = LEDMatrix[2] | 4; 
 LEDMatrix[4] = LEDMatrix[4] | 2;
 LEDMatrix[6] = LEDMatrix[6] | 2;
 LEDMatrix[6] = LEDMatrix[6] | 4;
}

void writedigit6_6(byte LEDMatrix[]){
 LEDMatrix[2] = LEDMatrix[2] | 4; 
 LEDMatrix[4] = LEDMatrix[4] | 2;
 LEDMatrix[4] = LEDMatrix[4] | 4;
 LEDMatrix[6] = LEDMatrix[6] | 2;
 LEDMatrix[6] = LEDMatrix[6] | 4;
}

void writedigit6_7(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 4; 
 LEDMatrix[2] = LEDMatrix[2] | 2;
 LEDMatrix[6] = LEDMatrix[6] | 2;
}

void writedigit6_8(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 4; 
 LEDMatrix[2] = LEDMatrix[2] | 4; 
 LEDMatrix[2] = LEDMatrix[2] | 2;
 LEDMatrix[4] = LEDMatrix[4] | 2;
 LEDMatrix[4] = LEDMatrix[4] | 4;
 LEDMatrix[6] = LEDMatrix[6] | 2;
 LEDMatrix[6] = LEDMatrix[6] | 4;
}

void writedigit6_9(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 4; 
 LEDMatrix[2] = LEDMatrix[2] | 4; 
 LEDMatrix[2] = LEDMatrix[2] | 2;
 LEDMatrix[4] = LEDMatrix[4] | 2;
 LEDMatrix[6] = LEDMatrix[6] | 2;
}

void writedigit6(byte LEDMatrix[], int newNum){
   switch ( newNum ) {
    case 0:
    writedigit6_0(LEDMatrix);   
    break; 
    case 1:
    writedigit6_1(LEDMatrix);   
    break;     
    case 2:
    writedigit6_2(LEDMatrix);   
    break;     
    case 3:
    writedigit6_3(LEDMatrix);   
    break;     
    case 4:
    writedigit6_4(LEDMatrix);   
    break;     
    case 5:
    writedigit6_5(LEDMatrix);   
    break;
    case 6:
    writedigit6_6(LEDMatrix);   
    break; 
    case 7:
    writedigit6_7(LEDMatrix);   
    break; 
    case 8:
    writedigit6_8(LEDMatrix);   
    break; 
    case 9:
    writedigit6_9(LEDMatrix);   
    break;     
  }
 
}


void writecolon(byte LEDMatrix[]){
 LEDMatrix[0] = LEDMatrix[0] | 128; 
}

void writeam(byte LEDMatrix[]){
 LEDMatrix[5] = LEDMatrix[5] | 2;
}
void writepm(byte LEDMatrix[]){
 LEDMatrix[3] = LEDMatrix[3] | 2;
}

void writespinner(byte LEDMatrix[], byte spinseed){
   switch (spinseed){
    case 1:
       LEDMatrix[6] = LEDMatrix[6] | 4;
    break;
    case 2:
       LEDMatrix[4] = LEDMatrix[4] | 4;
       LEDMatrix[6] = LEDMatrix[6] | 2;
    break;
    case 3:
       LEDMatrix[4] = LEDMatrix[4] | 2;
    break;
    case 4:
       LEDMatrix[2] = LEDMatrix[2] | 4;
       LEDMatrix[2] = LEDMatrix[2] | 2;
    break;
    case 5:
       LEDMatrix[0] = LEDMatrix[0] | 4;
    break;
    case 6:
       LEDMatrix[2] = LEDMatrix[2] | 4;
       LEDMatrix[2] = LEDMatrix[2] | 2;
    break;
    case 7:
       LEDMatrix[4] = LEDMatrix[4] | 2;
    break;
    case 8:
       LEDMatrix[4] = LEDMatrix[4] | 4;
       LEDMatrix[6] = LEDMatrix[6] | 2;
    break; 
    case 9:
       LEDMatrix[6] = LEDMatrix[6] | 4;
    break;
 } 
}

#endif

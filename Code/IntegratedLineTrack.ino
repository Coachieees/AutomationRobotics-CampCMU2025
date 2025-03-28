#include "CytronMotorDriver.h" //Include "Cytron Motor Library"
  
// Maker Line Sensor Pin Connection
#define LINE_D1   34
#define LINE_D2   35
#define LINE_D3   32
#define LINE_D4   33
#define LINE_D5   25
  
// Configure the motor driver.
CytronMD motorL(PWM_PWM, 27, 14);   // motor 1 = Left motor, M1A = Pin 3, M1B = Pin 9.
CytronMD motorR(PWM_PWM, 12, 13); // motor 2= right motor, M2A = Pin 10, M2B = Pin 11.
  
void setup() {
pinMode(LINE_D1, INPUT);
pinMode(LINE_D2, INPUT);
pinMode(LINE_D3, INPUT);
pinMode(LINE_D4, INPUT);
pinMode(LINE_D5, INPUT);
}
  
void loop() {
  // Perform line following
  int D1 = digitalRead(LINE_D1);
  int D2 = digitalRead(LINE_D2);
  int D3 = digitalRead(LINE_D3);
  int D4 = digitalRead(LINE_D4);
  int D5 = digitalRead(LINE_D5);

  if (D1==0 && D2==0 && D3==1 && D4==0 && D5==0) {
    motorL.setSpeed(100);   
    motorR.setSpeed(100);    //robot move forward
  }
   else if (D1==0 && D2==1 && D3==1 && D4==0 && D5==0) {
    motorL.setSpeed(80);   
    motorR.setSpeed(100);    //robot move slightly left
  }
  else if (D1==0 && D2==1 && D3==0 && D4==0 && D5==0) {
    motorL.setSpeed(60);   
    motorR.setSpeed(100);    //robot move slightly left
  }
  else if (D1==1 && D2==1 && D3==0 && D4==0 && D5==0) {
    motorL.setSpeed(30);   
    motorR.setSpeed(100);    //robot slowing down, move more to left
  }
  else if (D1==1 && D2==0 && D3==0 && D4==0 && D5==0) {
    motorL.setSpeed(0);   
    motorR.setSpeed(100);     //robot slowing down, move more to left
  }
   else if (D1==0 && D2==0 && D3==1 && D4==1 && D5==0) {
    motorL.setSpeed(100);   
    motorR.setSpeed(80);     //robot move slightly right
  }
  else if (D1==0 && D2==0 && D3==0 && D4==1 && D5==0) {
    motorL.setSpeed(100);   
    motorR.setSpeed(60);    //robot move slightly right
  }
  else if (D1==0 && D2==0 && D3==0 && D4==1 && D5==1) {
    motorL.setSpeed(100);   
    motorR.setSpeed(30);    //robot slowing down, move more to right
  }
  else if (D1==0 && D2==0 && D3==0 && D4==0 && D5==1) {
    motorL.setSpeed(100);   
    motorR.setSpeed(0);     //robot slowing down, move more to right
  }
  else {
  }
}

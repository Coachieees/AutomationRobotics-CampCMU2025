# 2. Line Tracking
หัวข้อนี้จะพูดถึงการใช้งานเซนเซอร์ตรวจจับเส้น (Line Sensor) เพื่อใช้ควบคุมการเคลื่อนที่ของหุ่นยนต์ให้สามารถเดินบนเส้นสนามได้

## หลักการทำงาน (Working Principle)
หลักการทำงานนี้ง่ายมาก คือบนบอร์ดจะมีเซ็นเซอร์อินฟราเรด (IR) จำนวน 5 ตัวตามรูปโดยที่แต่ละตัวสามารถแยกแยะพื้นผิวสว่างและพื้นผิวมืดได้ (สีขาว-สีดำ) ได้ตามรูป
- ถ้าเซนเซอร์ตัวตรงกลาง (หมายเลข 3) ตรวจจับว่าเป็นสีดำ และตัวอื่นทั้งหมดตรวจจับว่าเป็นสีขาว แปลว่า "หุ่นยนต์อยู่ตรงกลางเส้น -> เดินตรง"
- ถ้าเซนเซอร์ฝั่งซ้าย (หมายเลข 2) ตรวจจับว่าเป็นสีดำ และตัวอื่นทั้งหมดตรวจจับว่าเป็นสีขาว แปลว่า "หุ่นยนต์อยู่เยื้องไปฝั่งขวาเล็กน้อย -> หักซ้ายนิดหน่อย เพื่อกลับเข้ามาในเส้น"
- ถ้าเซนเซอร์ฝั่งซ้าย (หมายเลข 1) ตรวจจับว่าเป็นสีดำ และตัวอื่นทั้งหมดตรวจจับว่าเป็นสีขาว แปลว่า "หุ่นยนต์อยู่เยื้องไปฝั่งขวามากๆ -> หักซ้ายเยอะ ๆ เพื่อกลับเข้ามาในเส้น"
- ถ้าเซนเซอร์ฝั่งขวา (หมายเลข 4) ตรวจจับว่าเป็นสีดำ และตัวอื่นทั้งหมดตรวจจับว่าเป็นสีขาว แปลว่า "หุ่นยนต์อยู่เยื้องไปฝั่งขวาเล็กน้อย -> หักซ้ายนิดหน่อย เพื่อกลับเข้ามาในเส้น"
- ถ้าเซนเซอร์ฝั่งขวา (หมายเลข 5) ตรวจจับว่าเป็นสีดำ และตัวอื่นทั้งหมดตรวจจับว่าเป็นสีขาว แปลว่า "หุ่นยนต์อยู่เยื้องไปฝั่งขวามากๆ -> หักซ้ายเยอะ ๆ เพื่อกลับเข้ามาในเส้น"

![Alt text](https://github.com/Coachieees/AutomationRobotics-CampCMU2025/blob/main/Images/LineFollowPrinc.png?raw=true)

## การเชื่อมต่อสายไฟ (Wiring)
เชื่อมต่อสายไฟระหว่างบอร์ด Maker Line กับ ESP32 ตามรูป
![Alt text](https://github.com/Coachieees/AutomationRobotics-CampCMU2025/blob/main/Images/LineFollowDiagram.png?raw=true)

## การสอบเทียบเซนเซอร์ (Sensor Calibration)
1. เสียบสายสัญญาณเข้ากับบอร์ด ESP32 เพื่อจ่ายไฟให้เซนเซอร์
2. นำเซนเซอร์ไปวางบนพื้นสนาม โดยให้เซนเซอร์ยกลอยจากพื้นเล็กน้อย
3. กดปุ่ม Calibrate ที่ข้างบอร์ดค้างไว้ ไฟจะค่อยๆติดทีละดวงจนครบ แล้วทั้งหมดจะกระพริบ
4. เมื่อไฟกระพริบให้กวาดเซนเซอร์ทั้ง 5 ผ่านเส้นสีดำบนสนาม โดยกวาดไปกลับจำนวน 2-3 รอบ
5. เมื่อเสร็จแล้วให้กดปุ่ม Calibrate หนึ่งครั้งเป็นอันเสร็จสิ้น สังเกตได้จากเซนเซอร์ที่ตรวจจับเส้นสีดำได้ ไฟสีแดงบนเซนเซอร์จะติด

## การเขียนโปรแกรม (Programming)
เขียนโค้ดตามด้านล่างนี้ลงในโปรแกรม Arduino IDE
```cpp

// Maker Line Sensor Pin Connection
#define LINE_D1   34
#define LINE_D2   35
#define LINE_D3   32
#define LINE_D4   33
#define LINE_D5   25

void setup() {
  Serial.begin(9600);
  pinMode(LINE_D1, INPUT);
  pinMode(LINE_D2, INPUT);
  pinMode(LINE_D3, INPUT);
  pinMode(LINE_D4, INPUT);
  pinMode(LINE_D5, INPUT);
  }

void loop() {
    //Reading Sensor Value
    int D1 = digitalRead(LINE_D1);
    int D2 = digitalRead(LINE_D2);
    int D3 = digitalRead(LINE_D3);
    int D4 = digitalRead(LINE_D4);
    int D5 = digitalRead(LINE_D5);

    //Display Sensor Status (0=White, 1=Black)
    Serial.print(D1);Serial.print(" , ");
    Serial.print(D2);Serial.print(" , ");
    Serial.print(D3);Serial.print(" , ");
    Serial.print(D4);Serial.print(" , ");
    Serial.println(D5);
}
```
การทำงานของโค้ดนี้คือจะให้เซนเซอร์ IR ทั้ง 5 ตัวบนบอร์ด Maker Line อ่านค่าแสงบนสนาม 
- เซนเซอร์ตัวไหนอ่านเจอสีดำจะแสดงค่าสถานะเป็น 1
- เซนเซอร์ตัวไหนอ่านเจอสีขาวจะแสดงค่าสถานะเป็น 0

## การประยุกต์ใช้งานเซนเซอร์ (The application of sensors)
เราจะนำโปรแกรมที่เขียนมาด้านบนไปประยุกต์รวมกับมอเตอร์เพื่อให้หุ่นยนต์สามารถเดินตามเส้นได้โดยต่อวงจรได้ดังรูปและมีตัวอย่างโปรแกรมดังข้างล่าง
![Alt text](https://github.com/Coachieees/AutomationRobotics-CampCMU2025/blob/main/Images/IntLineFollowDiagram.png?raw=true)
```cpp
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
```

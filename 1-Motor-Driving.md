# 1. Driving The Motors
ในหัวข้อนี้จะควบคุมการทำงานของมอเตอร์ DC โดยมอเตอร์จะต่อเข้ากับบอร์ด Maker Drive ที่ทำหน้าที่เป็นตัวควบคุมมอเตอร์ จากนั้นจะต่อบอร์ดนี้เข้ากับ Microcontroller คือ ESP32 เพื่อเขียนโปรแกรมควบคุมการทำงานต่อไป

## การเชื่อมต่อสายไฟ (Wiring)
![Alt text](https://github.com/Coachieees/AutomationRobotics-CampCMU2025/blob/main/Images/MotorDriveDiagram.png?raw=true)
1. เชื่อมต่อมอเตอร์และแบตเตอรี่เข้ากับบอร์ด Maker Drive ดังรูป (ยังไม่ต้องต่อ Maker Drive กับบอร์ด ESP32)
2. เปิดสวิตช์ที่แบตเตอรี่เพื่อจ่ายไฟให้กับมอเตอร์
3. กดปุ่มทดสอบมอเตอร์ (Motor Test Button) บนบอร์ด Maker Drive
   - กดปุ่ม M1A และ M1B มอเตอร์ตัวที่ 1 จะหมุน โดยปุ่ม M1B มอเตอร์จะหมุนตรงข้ามกับ M1A
   - กดปุ่ม M2A และ M2B มอเตอร์ตัวที่ 2 จะหมุน โดยปุ่ม M2B มอเตอร์จะหมุนตรงข้ามกับ M2A

## การเขียนโปรแกรม (Programming)
1. ปิดสวิตช์ที่แบตเตอรี่ก่อนแล้วค่อยเชื่อมต่อบอร์ด Maker Drive เข้ากับ ESP32 ดังรูปด้านบนต่อได้เลย
2. เมื่อต่อเสร็จแล้วให้เข้าไปในโปรแกรม Arduino IDE จากนั้นกดลง Libary ดังนี้
   - ไปที่ Sketch -> Include Library -> Manage Libraries...
   - พิมพ์ค้นหาว่า Cytron Motor Drivers Library แล้วกด Install
   - ปิดโปรแกรมแล้วเปิดใหม่
3. เขียนโค้ดตามด้านล่างนี้ลงในโปรแกรม Arduino IDE
```cpp
 #include "CytronMotorDriver.h"

// Configure the motor driver.
CytronMD motor1(PWM_PWM, 32, 33);   // PWM 1A = Pin 32, PWM 1B = Pin 33.
CytronMD motor2(PWM_PWM, 25, 26); // PWM 2A = Pin 25, PWM 2B = Pin 26.

// The setup routine runs once when you press reset.
void setup() {
}

// The loop routine runs over and over again forever.
void loop() {
  motor1.setSpeed(128);   // Motor 1 runs forward at 50% speed.
  motor2.setSpeed(-128);  // Motor 2 runs backward at 50% speed.
  delay(1000); // Run for 1 second
  
  motor1.setSpeed(255);   // Motor 1 runs forward at full speed.
  motor2.setSpeed(-255);  // Motor 2 runs backward at full speed.
  delay(1000); // Run for 1 second

  motor1.setSpeed(0);     // Motor 1 stops.
  motor2.setSpeed(0);     // Motor 2 stops.
  delay(1000); // Stop for 1 second

  motor1.setSpeed(-128);  // Motor 1 runs backward at 50% speed.
  motor2.setSpeed(128);   // Motor 2 runs forward at 50% speed.
  delay(1000); // Run for 1 second
  
  motor1.setSpeed(-255);  // Motor 1 runs backward at full speed.
  motor2.setSpeed(255);   // Motor 2 runs forward at full speed.
  delay(1000); // Run for 1 second

  motor1.setSpeed(0);     // Motor 1 stops.
  motor2.setSpeed(0);     // Motor 2 stops.
  delay(1000); // Stop for 1 second
}
```
5. เสียบสายอัพโหลดโปรแกรมแล้วเลือก Port เชื่อมต่อ
6. กดปุ่มอัพโหลดโปรแกรมลงในบอร์ด ESP32
7. เมื่ออัพโหลดเสร็จ ให้กดเปิดสวิตช์แบตเตอรี่
8. มอเตอร์ทั้งสองตัวจะเกิดการหมุนเป็นจังหวะอย่างละ 1 วินาที

น้อง ๆ สามารถปรับความเร็วการหมุนได้ในโค้ดเช่นถ้าต้องการ
- ปรับความเร็วของมอเตอร์ตัวที่ 1 ให้ใช้คำสั่ง motor1.setSpeed(ค่าความเร็ว)
- ปรับความเร็วของมอเตอร์ตัวที่ 2 ให้ใช้คำสั่ง motor2.setSpeed(ค่าความเร็ว)

โดยค่าความเร็วสูงสุดคือ +-255 และ 0 คือหยุดนิ่ง ถ้าใส่เครื่องหมายติดลบหมายความว่ามอเตอร์จะหมุนในทิศตรงข้าม


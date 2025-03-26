# 3. Light Detection
ในหัวข้อนี้จะพูดถึงการใช้งานโมดูลเซนเซอร์ตรวจจับแสง (Light Sensor Module) ซึ่งมีลักษณะดังรูป
![Alt text](https://github.com/Coachieees/AutomationRobotics-CampCMU2025/blob/main/Images/LightSensor.png?raw=true)

## หลักการทำงาน (Working Principle)
บนโมดูลนี้จะมีตัวต้านทานแบบ LDR (Light Dependent Resistor) ซึ่งเป็นตัวต้านทานที่เปลี่ยนค่าตามความเข้มของแสง 
- เมื่อแสงมาก ค่าความต้านทานลดลง
- เมื่อแสงน้อย ค่าความต้านทานเพิ่มขึ้น
เราสามารถปรับความไว (Sensitivity) ของเซนเซอร์ได้โดยการหมุนปรับความไว
สัญญาณขาออกของโมดูลนี้จะมีให้เลือก 2 ประเภทคือ
1. แบบ Digital จะได้ค่าออกมาเป็น 0 กับ 1
   - ถ้ามีแสง ค่าจะเป็น 0
   - ถ้าไม่มีแสง ค่าจะเป็น 1
2. แบบ Analog จะได้ค่าออกมาเป็นเลขในช่วง 0-4000
   - ความเข้มแสงมากที่สุด (สว่างสุด) ค่าจะเป็น 0
   - ความเข้มแสงน้อยที่สุด (มืดสุด) ค่าจะเป็น 4000

## การต่อวงจร (Circuit Wiring)
น้อง ๆ สามารถต่อวงจรตามนี้ได้ตามรูปนี้เลย
![Alt text](https://github.com/Coachieees/AutomationRobotics-CampCMU2025/blob/main/Images/LightDetectDiagram.png?raw=true)
- ต้องการสัญญาณขาออกแบบ Analog -> ใช้ Pin D4
- ต้องการสัญญาณขาออกแบบ Digital -> ใช้ Pin D2

## การเขียนโปรแกรม (Programming)
- สำหรับสัญญาณขาออกแบบ Analog เขียนโค้ดได้ตามนี้
  ```c
  #define LDR_PIN   4

  void setup() {
  Serial.begin(9600);
  pinMode(LDR_PIN, INPUT);
  }
  void loop() {
  int value = analogRead(LDR_PIN);
  Serial.println(value);
  delay(100);
  }
  
  ```
- สำหรับสัญญาณขาออกแบบ Digital เขียนโค้ดได้ตามนี้
    ```c
  #define LDR_PIN   2

  void setup() {
  Serial.begin(9600);
  pinMode(LDR_PIN, INPUT);
  }
  void loop() {
  int value = digitalRead(LDR_PIN);
  Serial.println(value);
  delay(100);
  }
  
  ```

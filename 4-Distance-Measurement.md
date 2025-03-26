# 4.Distance Measurement
ในหัวข้อนี้จะกล่าวถึงการวัดระยะทางด้วยการใช้ Ultrasonic Sensor

## หลักการทำงาน (Working Principle)
โมดูล Ultrasonic จะปล่อยคลื่นอัลตราซาวนด์ความถี่ 40,000 เฮิรตซ์ ซึ่งจะเดินทางผ่านอากาศ และหากมีวัตถุหรือสิ่งกีดขวางอยู่บนเส้นทาง คลื่นจะสะท้อนกลับมายังโมดูล เมื่อพิจารณาจากเวลาเดินทางและความเร็วของเสียงแล้วจะสามารถคำนวณระยะทางได้
![Alt text](https://github.com/Coachieees/AutomationRobotics-CampCMU2025/blob/main/Images/UltrasonicPrinc.png?raw=true)

## การต่อวงจร (Circuit Wiring)
น้อง ๆ สามารถต่อวงจรตามนี้ได้เลย
![Alt text](https://github.com/Coachieees/AutomationRobotics-CampCMU2025/blob/main/Images/UltrasonicDiagram.png?raw=true)

## การเขียนโปรแกรม (Programming)
โปรแกรมวัดระยะทางโดยใช้ Ultrasonic Sensor สามารถเขียนได้ตามนี้
```c
#define trigPin 19
#define echoPin 18

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
```
การทำงานของโปรแกรม
- กำหนดขา trigPin (ขา 19) เป็นเอาต์พุต และ echoPin (ขา 18) เป็นอินพุต
- ส่งพัลส์ความถี่สูง (Trigger Pulse) ออกทาง trigPin เป็นเวลา 10 ไมโครวินาที
- รับสัญญาณสะท้อนกลับที่ echoPin และวัดระยะเวลาที่คลื่นเดินทางไป-กลับ
- คำนวณระยะทางโดยใช้สูตร: distance = (duration × 0.0343)/2
  โดย 0.0343 คือความเร็วเสียงในอากาศ (343 เมตร/วินาที) ที่แปลงเป็น เซนติเมตร/ไมโครวินาที
- แสดงผลระยะทางผ่าน Serial Monitor
- หน่วงเวลา 100 มิลลิวินาที แล้วเริ่มวัดใหม่

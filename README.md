# Automation & Robotics Camp 2025
แนวทางการเขียนโปรแกรมควบคุมหุ่นยนต์ในค่ายวิศวกรรมระบบอัตโนมัติและหุ่นยนต์ Entaneer Academy
## 1. Installing the IDE and Initial Setup
ก่อนอื่นเราต้องลงโปรแกรม IDE สำหรับเขียนโค้ดก่อน โดยเราจะใช้โปรแกรม Arduino IDE น้องๆสามารถดาวน์โหลดได้ตามขั้นต่อไปตอนนี้
1. เข้าไปที่เว็ปไซต์ https://www.arduino.cc/en/software แล้วกดเลือกระบบปฎิบัติการของเครื่องคอมพิวเตอร์ที่น้องๆใช้งาน
2. เมื่อคลิกเลือกระบบปฎิบัติการแล้ว เว็ปจะเด้งไปที่หน้าให้ Donate ให้กดที่ปุ่ม Just Download จึงจะโหลดโปรแกรมได้
3. กดเข้าไปในไฟล์ที่โหลดมาแล้วทำการติดตั้งโปรแกรมโดยกด I agree -> Next -> Install แล้วรอติดตั้ง
4. เสร็จแล้วให้กด Run แล้วจะเข้าสู่โปรแกรม Arduino IDE
5. ทำการติดตั้ง Boards Manager ของบอร์ด ESP32 โดยกดไปที่ File -> Preferences
6. ที่ช่อง Additional Boards Manager URLs ให้ใส่ลิ้งค์นี้ลงไป https://dl.espressif.com/dl/package_esp32_index.json แล้วกด OK
7. คลิกไปที่เมนู Tools -> Board -> Board Manager
8. พิมพ์คำว่า esp32 ลงในช่องค้นหาด้านบนจะเจอ esp32 by Espressif Systems จากน้้นกด Install
9. เมื่อติดตั้งเสร็จสิ้น ในหน้าต่าง Board จะปรากฏประเภทของบอร์ด ESP32 ขึ้นมาให้เลือกใช้งาน ให้เลือกไปที่ ESP32 Dev Module
10. เชื่อมต่อบอร์ด ESP32 เข้ากับคอมพิวเตอร์จะมี Port ใหม่ (COM...) เด้งมาที่ช่อง Unknown ให้กดคลิกที่ Port นั้น
11. จากนั้นจะขึ้นหน้าต่าง Select Other Board and Port ให้กดเลือกชนิด Boards เป็น ESP32 Dev Module
12. การเชื่อมต่อเป็นอันเสร็จสิ้น ให้น้องๆลองอัพโค้ดแล้ว Run เล่นๆได้เลย

ดูเพิ่มเติมได้ที่ [https://www.cybertice.com](https://www.cybertice.com/article/226/%E0%B8%AA%E0%B8%AD%E0%B8%99%E0%B9%83%E0%B8%8A%E0%B9%89%E0%B8%87%E0%B8%B2%E0%B8%99-esp32-%E0%B9%80%E0%B8%A3%E0%B8%B4%E0%B9%88%E0%B8%A1%E0%B8%95%E0%B9%89%E0%B8%99%E0%B9%83%E0%B8%8A%E0%B9%89%E0%B8%87%E0%B8%B2%E0%B8%99-%E0%B8%95%E0%B8%B4%E0%B8%94%E0%B8%95%E0%B8%B1%E0%B9%89%E0%B8%87%E0%B9%82%E0%B8%9B%E0%B8%A3%E0%B9%81%E0%B8%81%E0%B8%A3%E0%B8%A1%E0%B9%80%E0%B8%9A%E0%B8%B7%E0%B9%89%E0%B8%AD%E0%B8%87%E0%B8%95%E0%B9%89%E0%B8%99-esp32?gad_source=1&gclid=Cj0KCQjw4v6-BhDuARIsALprm31akMaeTpsA0YPJpLaqtORyGYSsdzhiQYmdc5DCjR78tvGF636VLUMaAoP6EALw_wcB)

## 2. Driving the Motors
![Alt text](https://github.com/Coachieees/AutomationRobotics-CampCMU2025/blob/main/Images/MotorDriveDiagram.png?raw=true)
1. เชื่อมต่อมอเตอร์และแบตเตอรี่เข้ากับบอร์ด Maker Drive ดังรูป (ยังไม่ต้องต่อ Maker Drive กับบอร์ด ESP32)
2. เปิดสวิตช์ที่แบตเตอรี่เพื่อจ่ายไฟให้กับมอเตอร์แล้วลองกดปุ่มทดสอบมอเตอร์ (Motor Test Button) บนบอร์ด Maker Drive
3. ถ้ามอเตอร์ทำงานได้แล้ว ให้ปิดแหล่งจ่ายไฟแล้วเชื่อมต่อบอร์ด Maker Drive เข้ากับ ESP32 ดังรูปต่อได้เลย
4. เมื่อต่อเสร็จแล้วให้เข้าไปในโปรแกรม Arduino IDE จากนั้นกดลง Libary ดังนี้ Sketch -> Include Library -> Manage Libraries...
5. จากนั้นพิมพ์ค้นหาว่า Cytron Motor Drivers Library แล้วกด Install จากนั้นปิดโปรแกรมแล้วเปิดใหม่
6. เข้าไปใน Github แล้วโหลดไฟล์โค้ดชื่อ DrivingMotors.ino แล้วกดเปิดโค้ดนี้ใน Arduino IDE
7. อัพโหลดโปรแกรมลงในบอร์ด ESP32 จากนั้นกดเปิดสวิตช์แบตเตอรี่
8. มอเตอร์ทั้งสองตัวจะเกิดการหมุนเป็นจังหวะอย่างละ 1 วินาที

น้อง ๆ สามารถปรับความเร็วการหมุนได้ในโค้ดเช่นถ้าต้องการ
- ปรับความเร็วของมอเตอร์ตัวที่ 1 ให้ใช้คำสั่ง motor1.setSpeed(ค่าความเร็ว)
- ปรับความเร็วของมอเตอร์ตัวที่ 2 ให้ใช้คำสั่ง motor2.setSpeed(ค่าความเร็ว)

โดยค่าความเร็วสูงสุดคือ +-255 และ 0 คือหยุดนิ่ง ถ้าใส่เครื่องหมายติดลบหมายความว่ามอเตอร์จะหมุนในทิศตรงข้าม

## 3. Tracking the Line
1. เชื่อมต่อมอเตอร์และแบตเตอรี่เข้ากับบอร์ด Maker Drive ดังรูป (ยังไม่ต้องต่อ Maker Drive กับบอร์ด ESP32)

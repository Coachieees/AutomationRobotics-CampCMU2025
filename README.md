# Automation & Robotics Camp 2025
แนวทางการเขียนโปรแกรมควบคุมหุ่นยนต์ในค่ายวิศวกรรมระบบอัตโนมัติและหุ่นยนต์ Entaneer Academy
## Installing the IDE and Initial Setup
ก่อนอื่นเราต้องลงโปรแกรม IDE สำหรับเขียนโค้ดก่อน โดยเราจะใช้โปรแกรม Arduino IDE น้องๆสามารถดาวน์โหลดได้ตามขั้นต่อไปตอนนี้
1. เข้าไปที่เว็ปไซต์ https://www.arduino.cc/en/software แล้วกดเลือกระบบปฎิบัติการของเครื่องคอมพิวเตอร์ที่น้องๆใช้งาน
2. เมื่อคลิกเลือกระบบปฎิบัติการแล้ว เว็ปจะเด้งไปที่หน้าให้ Donate ให้กดที่ปุ่ม Just Download จึงจะโหลดโปรแกรมได้
3. กดเข้าไปในไฟล์ที่โหลดมาแล้วทำการติดตั้งโปรแกรมโดยกด I agree -> Next -> Install แล้วรอติดตั้ง
4. เสร็จแล้วให้กด Run แล้วจะเข้าสู่โปรแกรม Arduino IDE
5. ทำการติดตั้ง Boards Manager ของบอร์ด ESP32 โดยกดไปที่ File -> Preferences
6. ที่ช่อง Additional Boards Manager URLs ให้ใส่ลิ้งค์นี้ลงไป https://dl.espressif.com/dl/package_esp32_index.json แล้วกด OK
7. คลิกไปที่เมนู Tools -> Board -> Board Manager
8. พิมพ์คำว่า ESP32 ลงในช่องค้นหาด้านบน แล้วกด Install
9. เมื่อติดตั้งเสร็จสิ้น ในหน้าต่าง Board จะปรากฏประเภทของบอร์ด ESP32 ขึ้นมาให้เลือกใช้งาน ให้เลือกไปที่ ESP32 Dev Module

## Driving the Motors
1.เชื่อมต่อมอเตอร์และแบตเตอรี่เข้ากับบอร์ด Maker Drive ดังรูป
![Alt text](https://github.com/Coachieees/ENT-CMU-Camp2025/blob/main/Images/Maker%20Drive%20Overview.png?raw=true)

# Automation & Robotics Camp 2025
แนวทางการเขียนโปรแกรมควบคุมหุ่นยนต์ในค่ายวิศวกรรมระบบอัตโนมัติและหุ่นยนต์ Entaneer Academy
## การติดตั้งโปรแกรม IDE
ก่อนอื่นเราต้องลงโปรแกรม IDE สำหรับเขียนโค้ดก่อน โดยเราจะใช้โปรแกรม Arduino IDE น้องๆสามารถดาวน์โหลดได้ตามขั้นต่อไปตอนนี้
1. เข้าไปที่เว็ปไซต์ https://www.arduino.cc/en/software แล้วกดเลือกระบบปฎิบัติการของเครื่องคอมพิวเตอร์ที่น้องๆใช้งาน
2. เมื่อคลิกเลือกระบบปฎิบัติการแล้ว เว็ปจะเด้งไปที่หน้าให้ Donate ให้กดที่ปุ่ม Just Download จึงจะโหลดโปรแกรมได้
3. กดเข้าไปในไฟล์ที่โหลดมาแล้วทำการติดตั้งโปรแกรมโดยกด I agree -> Next -> Install แล้วรอติดตั้ง
4. เสร็จแล้วให้กด Run แล้วจะเข้าสู่โปรแกรม Arduino IDE

## การติดตั้ง ESP32 ในโปรแกรม IDE
1. ทำการติดตั้ง Boards Manager ของบอร์ด ESP32 โดยกดไปที่ File -> Preferences
2. ที่ช่อง Additional Boards Manager URLs ให้ใส่ลิ้งค์นี้ลงไป https://dl.espressif.com/dl/package_esp32_index.json แล้วกด OK
3. คลิกไปที่เมนู Tools -> Board -> Board Manager
4. พิมพ์คำว่า esp32 ลงในช่องค้นหาด้านบนจะเจอ esp32 by Espressif Systems จากน้้นกด Install
5. เมื่อติดตั้งเสร็จสิ้น ในหน้าต่าง Board จะปรากฏประเภทของบอร์ด ESP32 ขึ้นมาให้เลือกใช้งาน ให้เลือกไปที่ ESP32 Dev Module
6. เชื่อมต่อบอร์ด ESP32 เข้ากับคอมพิวเตอร์จะมี Port ใหม่ (COM...) เด้งมาที่ช่อง Unknown ให้กดคลิกที่ Port นั้น
7. จากนั้นจะขึ้นหน้าต่าง Select Other Board and Port ให้กดเลือกชนิด Boards เป็น ESP32 Dev Module
8. การเชื่อมต่อเป็นอันเสร็จสิ้น ให้น้องๆลองอัพโค้ดแล้ว Run เล่นๆได้เลย

ดูเพิ่มเติมได้ที่ [https://www.cybertice.com](https://www.cybertice.com/article/226/%E0%B8%AA%E0%B8%AD%E0%B8%99%E0%B9%83%E0%B8%8A%E0%B9%89%E0%B8%87%E0%B8%B2%E0%B8%99-esp32-%E0%B9%80%E0%B8%A3%E0%B8%B4%E0%B9%88%E0%B8%A1%E0%B8%95%E0%B9%89%E0%B8%99%E0%B9%83%E0%B8%8A%E0%B9%89%E0%B8%87%E0%B8%B2%E0%B8%99-%E0%B8%95%E0%B8%B4%E0%B8%94%E0%B8%95%E0%B8%B1%E0%B9%89%E0%B8%87%E0%B9%82%E0%B8%9B%E0%B8%A3%E0%B9%81%E0%B8%81%E0%B8%A3%E0%B8%A1%E0%B9%80%E0%B8%9A%E0%B8%B7%E0%B9%89%E0%B8%AD%E0%B8%87%E0%B8%95%E0%B9%89%E0%B8%99-esp32?gad_source=1&gclid=Cj0KCQjw4v6-BhDuARIsALprm31akMaeTpsA0YPJpLaqtORyGYSsdzhiQYmdc5DCjR78tvGF636VLUMaAoP6EALw_wcB)

## การเชื่อมต่อและเขียนโปรแกรมควบคุมเซนเซอร์ต่าง ๆ
- การขับมอเตอร์ (Motor Driving) ดูได้ที่ [1.Motor Driving](./1.Motor Driving.md)
- การใช้งานเซนเซอร์ตรวจจับเส้น (Line Sensor) ดูได้ที่ [2.Line Tracking](./2.Line Tracking.md)
- การใช้งานเซนเซอร์ตรวจจับความเข้มแสง (Light Sensor) ดูได้ที่ [3.Light Detection](./3.Light Detection.md)
- การใช้งานเซนเซอร์วัดระยะทาง (Ultrasonic Sensor) ดูได้ที่ [4.Distance Measurement](./4.Distance Measurement.md)

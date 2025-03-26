# 4.Distance Measurement
## หลักการทำงาน (Working Principle)
โมดูล Ultrasonic จะปล่อยคลื่นอัลตราซาวนด์ความถี่ 40,000 เฮิรตซ์ ซึ่งจะเดินทางผ่านอากาศ และหากมีวัตถุหรือสิ่งกีดขวางอยู่บนเส้นทาง คลื่นจะสะท้อนกลับมายังโมดูล เมื่อพิจารณาจากเวลาเดินทางและความเร็วของเสียงแล้วจะสามารถคำนวณระยะทางได้


## การต่อวงจร (Circuit Wiring)

## การเขียนโปรแกรม (Programming)
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

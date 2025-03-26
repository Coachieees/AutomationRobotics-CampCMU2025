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

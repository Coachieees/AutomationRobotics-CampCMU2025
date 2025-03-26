#define LDR_AoPIN   4
#define LDR_DoPIN   2

void setup() {
Serial.begin(9600);
pinMode(LDR_AoPIN, INPUT);
pinMode(LDR_DoPIN, INPUT);
}

void loop() {
int AnalogValue = analogRead(LDR_AoPIN);
Serial.println(AnalogValue);

int DigitalValue = digitalRead(LDR_DoPIN);
Serial.println(DigitalValue);
  
delay(100);
}

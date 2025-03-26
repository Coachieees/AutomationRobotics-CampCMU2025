# 5. Web/App Control
ในเนื้อหาส่วนนี้จะเป็นการใช้บอร์ด ESP32 ควบคุมมอเตอร์หุ่นยนต์ผ่าน Wifi ด้วย Website และ Application ในมือถือ โดยจะใช้ Web/App ของ Blynk

## การใช้งาน Blynk กับ ESP32
1. เข้าไปในเว็ปไซต์ [Blynk](https://blynk.io/)
2. สมัครลงทะเบียนใช้งานด้วยอีเมลของน้อง ๆ ให้เรียบร้อย
3. ทำตามคลิปวีดีโอนี้เลย


## โปรแกรมทดสอบ Blynk (Blynk Testing Program)
```c
//------------------------------------------------------------//
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""
//------------------------------------------------------------//

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";  //Enter Wifi Name
char pass[] = "";  //EnterWifi Password

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}


void setup()
{
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

int MotorSpeed = 0;
int forward = 0;
int backward = 0;
int left = 0;
int right = 0;

BLYNK_WRITE(V0) {
    MotorSpeed = param.asInt();
}

BLYNK_WRITE(V1) { 
    forward = param.asInt();
}

BLYNK_WRITE(V2) { 
    backward = param.asInt();
}

BLYNK_WRITE(V3) { 
    left = param.asInt();
}

BLYNK_WRITE(V4) { 
    right = param.asInt();
}

void loop()
{
  Blynk.run();
  timer.run();

  Serial.print("Speed: ");Serial.println(MotorSpeed);
  Serial.print("Forward: ");Serial.print(forward);Serial.print(" |  Backward: ");Serial.print(backward);Serial.print(" |  Left: ");Serial.print(left);Serial.print(" |  Right: ");Serial.println(right);

  delay(10);
}

```

## โปรแกรมควบคุมมอเตอร์ (Motor Control Program)
```c
//------------------------------------------------------------//
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""
//------------------------------------------------------------//

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "CytronMotorDriver.h"

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

BlynkTimer timer;

CytronMD motorL(PWM_PWM, 27, 14);
CytronMD motorR(PWM_PWM, 12, 13);

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}


void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

int MotorSpeed = 0;
int forward = 0;
int backward = 0;
int left = 0;
int right = 0;
int Speed1 = 0;
int Speed2 = 0;

BLYNK_WRITE(V0) {
    MotorSpeed = param.asInt();
}

BLYNK_WRITE(V1) { 
    forward = param.asInt();
}

BLYNK_WRITE(V2) { 
    backward = param.asInt();
}

BLYNK_WRITE(V3) { 
    left = param.asInt();
}

BLYNK_WRITE(V4) { 
    right = param.asInt();
}

void loop()
{
  Blynk.run();
  timer.run();

  Serial.print("Speed: ");Serial.println(MotorSpeed);
  Serial.print("F: ");Serial.print(forward);Serial.print(" |  B: ");Serial.print(backward);Serial.print(" |  L: ");Serial.print(left);Serial.print(" |  R: ");Serial.println(right);

  if (forward==1){
    Speed1 = MotorSpeed*1;
    Speed2 = MotorSpeed*1;
  }
  else if (backward==1){
    Speed1 = MotorSpeed*-1;
    Speed2 = MotorSpeed*-1;
  } 
  else if (left==1){
    Speed1 = MotorSpeed*1;
    Speed2 = MotorSpeed*-1;
  }
  else if (right==1){
    Speed1 = MotorSpeed*-1;
    Speed2 = MotorSpeed*1;
  }
  else {
    Speed1 = 0;
    Speed2 = 0;
  }

  Serial.print("Speed1: ");Serial.print(Speed1);Serial.print(" |  Speed2: ");Serial.println(Speed2);
  motorL.setSpeed(Speed1);   
  motorR.setSpeed(Speed2);

  delay(10);
}

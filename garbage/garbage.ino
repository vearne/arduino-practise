#include <Servo.h>

int infraredPin = 2;
int lightPin = 6;
int steerPin = 9;
int closeAngle = 0;
int openAngle = 80;
Servo servo;

void setup() {
  pinMode(infraredPin, INPUT);
  pinMode(steerPin, OUTPUT);
  pinMode(lightPin, OUTPUT);
  servo.attach(steerPin);

  // 初始状态: 垃圾桶盖子是关闭的
  servo.write(closeAngle);
}

void loop() {
  if (digitalRead(infraredPin) == 0) {         //检测到障碍物，输出低电平
    digitalWrite(lightPin, HIGH);     //亮灯
    // 垃圾桶开盖
    servo.write(openAngle);
    delay(3000);    // 等待3秒
    // clear
    digitalWrite(lightPin, LOW);      // 灭灯
    servo.write(closeAngle);
  } 
  delay(200);
}

#include <math.h>

// ====== 引脚定义（按你实际修改）======
#define PIN_A 2
#define PIN_B 3
#define PIN_PWM 9

#define IN1 45
#define IN2 47
#define IN3 49
#define IN4 51

// ====== 参数 ======
const float PULSE_TO_MM = 0.3140;
const int SPEED = 200;

// ====== 状态变量 ======
volatile long pulseCount = 0;
bool stopFlag = false;
String cmd = "";

// ====== 编码器中断 ======
void encoderISR() {
  pulseCount++;
}

// ====== 初始化 ======
void setup() {
  pinMode(PIN_A, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_A), encoderISR, RISING);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(PIN_PWM, OUTPUT);

  Serial.begin(115200);

  stopMotor();
  Serial.println("READY");
}

// ====== 主循环 ======
void loop() {
  readCommand();
}

// ====== 串口读取 ======
void readCommand() {
  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n' || c == '\r') {
      if (cmd.length() > 0) {
        cmd.trim();
        handleCommand(cmd);
        cmd = "";
      }
    } else {
      cmd += c;
    }
  }
}

// ====== 命令处理 ======
void handleCommand(String command) {
  command.toUpperCase();

  if (command == "ON") {
    Serial.println("START SEQUENCE");
    stopFlag = false;
    runSequence();
  }
  else if (command == "OFF") {
    Serial.println("STOP");
    stopFlag = true;
    stopMotor();
  }
}

// ====== 动作序列 ======
void runSequence() {

  moveDistance(250);   // 前300
  if (stopFlag) return;

  moveDistance(100);   // 前100
  if (stopFlag) return;

  moveDistance(-200);  // 后200
  if (stopFlag) return;

  moveDistance(-150);  // 后200
  if (stopFlag) return;

  stopMotor();
  Serial.println("DONE");
}

// ====== 核心函数：移动距离 ======
void moveDistance(float mm) {

  pulseCount = 0;
  long targetPulse = abs(mm / PULSE_TO_MM);

  if (mm > 0) {
    forward();
  } else {
    backward();
  }

  analogWrite(PIN_PWM, SPEED);

  while (pulseCount < targetPulse) {

    // ⭐关键：实时检查串口
    checkSerialDuringMove();

    if (stopFlag) {
      stopMotor();
      Serial.println("INTERRUPTED");
      return;
    }
  }

  stopMotor();
  delay(300);
}

// ====== 电机控制 ======
void forward() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(PIN_PWM, 0);
}

void checkSerialDuringMove() {

  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n' || c == '\r') {
      if (cmd.length() > 0) {
        cmd.trim();

        if (cmd.equalsIgnoreCase("OFF")) {
          stopFlag = true;
          Serial.println("STOP RECEIVED");
        }

        cmd = "";
      }
    } else {
      cmd += c;
    }
  }
}
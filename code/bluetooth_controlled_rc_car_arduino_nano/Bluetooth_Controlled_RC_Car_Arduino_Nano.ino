#include <SoftwareSerial.h>

// Bluetooth pins
#define BT_RX 10   // Arduino RX ← HC-05 TX
#define BT_TX 11   // Arduino TX → HC-05 RX

SoftwareSerial bluetooth(BT_RX, BT_TX);

// motor one
#define IN1 2
#define IN2 3

// motor two
#define IN3 4
#define IN4 5

void setup() {
  Serial.begin(9600);       // USB monitor
  bluetooth.begin(9600);   // HC-05 baud rate

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  if (bluetooth.available() > 0) {
    char value = bluetooth.read();
    Serial.println(value);   // debug

    if (value == 'U') {
      Forward();
    } else if (value == 'D') {
      Backward();
    } else if (value == 'S') {
      Stop();
    } else if (value == 'L') {
      Left();
    } else if (value == 'R') {
      Right();
    }
  }
}

void Forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void Left() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Right() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


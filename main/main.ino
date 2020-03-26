#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial bt(12, 11); // RX,TX

Servo servos[8];
/*                 Front
   Servo0 - Servo2 |--| Servo4 - Servo6
   Servo1 - Servo3 |--| Servo5 - Servo7
*/
uint8_t pos[8];
uint8_t cpos[8];
int8_t s1 = -10;
int8_t s3 = -10;
int8_t s7 = +20;

uint8_t fullStep = 110;
uint8_t halfStep = 110;

uint8_t b_fullStep = 70;
uint8_t b_halfStep = 70;

long previousMillis = 0;
long interval = 1000;

void servoReset(int8_t i) {
  pos[i - 4] = 90;
  cpos[i - 4] = 90;
  if (i - 4 == 1) {
    pos[i - 4] += s1;
    cpos[i - 4] += s1;
  } else if (i - 4 == 7) {
    pos[i - 4] += s7;
    cpos[i - 4] += s7;
  } else if (i - 4 == 3) {
    pos[i - 4] += s3;
    cpos[i - 4] += s3;
  }
  servos[i - 4].write(pos[i - 4]);
  delay(50);
}

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  for (int8_t i = 4; i < 12; i++) {
    servos[i - 4].attach(i);
    servoReset(i);
  }
}



void r_walk(uint8_t v = 2000) {
  /*                 Front
        Servo0 - Servo2 |--| Servo4 - Servo6
        Servo1 - Servo3 |--| Servo5 - Servo7
  */
  Serial.println("Right Walking..");
  uint16_t wait = 4000 / v;
  servos[0].write(80);
  servos[1].write(80);
  servos[2].write(30);
  servos[3].write(30);
  servos[4].write(80);
  servos[5].write(80);
  servos[6].write(20);
  servos[7].write(50);
  
  /*
    servos[0].write(70);
    servos[1].write(80);
    servos[6].write(50);
    servos[7].write(90);

    servos[3].write(30);
    servos[5].write(120);
    servos[2].write(30);
    servos[4].write(120);

    for (uint8_t i = 30; i < 130; i++) {
    servos[0].write(i);
    servos[1].write(i - 10);
    delay(wait);
    }
  */
  /*
    servos[0].write(80);
    servos[7].write(80);
    servos[4].write(80);
    servos[5].write(80);

    servos[2].write(60);
    servos[6].write(20);
    servos[3].write(30 + 20);
    servos[1].write(80 - 20);

    for (uint8_t i = 80; i < 150; i++) {
    servos[1].write(180-i - 20);
    delay(wait);
    }
    for (uint8_t i = 30; i < 110; i++) {
    servos[3].write(180-i + 20);
    delay(wait);
    }

    for (uint8_t i = 150; i > 30; i--) {
    servos[1].write(180-i - 20);
    delay(wait / 2);
    }
    for (uint8_t i = 110; i > 30; i--) {
    servos[3].write(180-i + 20);
    delay(wait / 2);
    }
  */
}

void l_walk(uint8_t v = 2000) {
  /*                 Front
      Servo0 - Servo2 |--| Servo4 - Servo6
      Servo1 - Servo3 |--| Servo5 - Servo7
  */
  Serial.println("Left Walking..");
  uint16_t wait = 4000 / v;

  servos[0].write(80);
  servos[1].write(80);
  servos[2].write(85);
  servos[3].write(85);

  servos[6].write(50);
  servos[7].write(90);
  servos[5].write(120);
  servos[4].write(120);
  /*
    servos[0].write(80);
    servos[1].write(80);
    servos[2].write(80);
    servos[3].write(80);

    servos[4].write(80);
    servos[6].write(20);
    servos[5].write(30);
    servos[7].write(80);

    for (uint8_t i = 80; i < 150; i++) {
    servos[7].write(i);
    delay(wait);
    }
    for (uint8_t i = 30; i < 110; i++) {
    servos[5].write(i);
    delay(wait);
    }

    for (uint8_t i = 150; i > 30; i--) {
    servos[7].write(i);
    delay(wait / 2);
    }

    for (uint8_t i = 110; i > 30; i--) {
    servos[5].write(i);
    delay(wait / 2);
    }
  */
}


void walk(uint8_t v = 1000) {
  /*                 Front
    Servo0 - Servo2 |--| Servo4 - Servo6
    Servo1 - Servo3 |--| Servo5 - Servo7
  */
  Serial.println("Walking..");
  uint16_t wait = 10000 / v;
  servos[0].write(80);
  servos[6].write(20);
  servos[1].write(80);
  servos[3].write(85);
  servos[5].write(80);
  servos[7].write(50);
  delay(250);
  servos[2].write(20);
  servos[4].write(120);
  delay(250);
  servos[2].write(70);
  servos[4].write(70);
  delay(250);
  servos[3].write(50);
  servos[5].write(100);
  delay(250);
  servos[3].write(85);
  servos[5].write(80);
  /*
    for (uint8_t i = 80; i < 130; i++) {
    servos[4].write(i - 20);
    servos[6].write(i - 30);

    servos[3].write(180 - i + s3);
    servos[1].write(180 - i - s1-10);
    delay(wait);
    }
    for (uint8_t i = 130; i > 80; i--) {
    servos[4].write(i - 20);
    servos[6].write(i - 30);

    servos[3].write(180 - i + s3);
    servos[1].write(180 - i - s1-10);
    delay(wait);
    }
    //reverse
    for (uint8_t i = 80; i < 130; i++) {
    servos[0].write(180 - i);
    servos[2].write(180 - i - 20);

    servos[5].write(i - 20);
    servos[7].write(i - s7+20);
    delay(wait);
    }
    for (uint8_t i = 130; i > 80; i--) {
    servos[0].write(180 - i);
    servos[2].write(180 - i - 20);

    servos[5].write(i - 20);
    servos[7].write(i - s7+20);
    delay(wait);
    }
  */
}

void loop() {
  if (bt.available())
  {
    char data = bt.read();
    Serial.print("gelen veri:"); Serial.println(data);
    if (data == 'F') {
      walk();
    } else if (data == 'L') {
      l_walk();
    } else if (data == 'R') {
      r_walk();
    } else if (data == 'U') {
      servos[0].write(70);
      servos[1].write(80);
      servos[6].write(50);
      servos[7].write(90);

      servos[3].write(30);
      servos[5].write(120);
      servos[2].write(30);
      servos[4].write(120);
    } else if (data == 'D') {
      servos[0].write(70);
      servos[1].write(80);
      servos[6].write(50);
      servos[7].write(90);

      servos[3].write(140);
      servos[5].write(30);
      servos[2].write(120);
      servos[4].write(20);
    }
  }

}

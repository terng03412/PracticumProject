#include <SPI.h>
#include <RFID.h>
#include <Servo.h>

RFID rfid(PIN_PB2, PIN_PB1);

Servo servo;

int buttonState = 0;
int waitingState = 0;
int turnOnState = 0;
int pos = 0;

#define LED_onboard  PIN_PD3
#define Servo_port PIN_PB0
#define Com_port PIN_PD0

#define Button_Perf PIN_PC3
#define Led_Red PIN_PC0
#define Led_Yel PIN_PC1
#define Led_Gre PIN_PC2

int serNum0;
int serNum1;
int serNum2;
int serNum3;
int serNum4;


void setup() {
  SPI.begin();

  rfid.init();
  servo.attach(Servo_port);

  pinMode(LED_onboard, OUTPUT);
  pinMode(Button_Perf, INPUT_PULLUP);

  pinMode(Led_Red, OUTPUT);
  pinMode(Led_Yel, OUTPUT);
  pinMode(Led_Gre, OUTPUT);
  pinMode(Com_port, OUTPUT);
  waitingState = 0;

  serNum0 = serNum1 = serNum2 = serNum3 = serNum4 = 0;
}

void Beep_2() {

  digitalWrite(Led_Red, HIGH);
  digitalWrite(Led_Yel, HIGH);
  digitalWrite(Led_Gre, HIGH);

  delay(200);

  digitalWrite(Led_Red, LOW);
  digitalWrite(Led_Yel, LOW);
  digitalWrite(Led_Gre, LOW);


}

void BEEP_LED(int state) {
  if (state == 1) {
    digitalWrite(Led_Red, HIGH);
    delay(100);
    digitalWrite(Led_Yel, HIGH);
    delay(100);
    digitalWrite(Led_Gre, HIGH);
    delay(100);
    digitalWrite(Led_Red, LOW);
    delay(100);
    digitalWrite(Led_Yel, LOW);
    delay(100);
    digitalWrite(Led_Gre, LOW);
    delay(100);
  }
  else {
    return;
  }

}


void loop() {


  buttonState = digitalRead(PIN_PC3);

  servo.write(pos);

  if (buttonState == HIGH) {
    digitalWrite(LED_onboard , HIGH);

  } else if (waitingState == 0) {
    digitalWrite(LED_onboard, LOW );
    waitingState = 1;
  }
  delay(100);

  if (buttonState == HIGH && waitingState == 1) {

    if (rfid.isCard()) {
      if (rfid.readCardSerial()) {

        serNum0 = rfid.serNum[0];
        serNum1 = rfid.serNum[1];
        serNum2 = rfid.serNum[2];
        serNum3 = rfid.serNum[3];
        serNum4 = rfid.serNum[4];

        delay(1000);
        Beep_2();
      }
      BEEP_LED(waitingState);
      waitingState = 0;
      delay(1000);
    }
  }

  BEEP_LED(waitingState);



  if (rfid.isCard()) {
    Beep_2();
    if (rfid.readCardSerial()) {
      if (rfid.serNum[0] == serNum0
          && rfid.serNum[1] == serNum1
          && rfid.serNum[2] == serNum2
          && rfid.serNum[3] == serNum3
          && rfid.serNum[4] == serNum4
         ) {

        digitalWrite(LED_onboard, LOW);
        if (pos == 0) {
          pos = 60;
          turnOnState = 1;
        }
        else {
          pos = 0;
          turnOnState = 0;
        }

        delay(1000);
      }
    }

  } else {
    digitalWrite(LED_onboard, HIGH);
    //    servo.write(0);
    waitingState = 0;

  }
  rfid.halt();

  if (turnOnState == 1) {
    digitalWrite(Com_port , HIGH);
  }
  else {
    digitalWrite(Com_port , LOW);
  }

}

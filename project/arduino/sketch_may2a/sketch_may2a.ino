#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//* define the Rx, Ry and switch_joystick_button pins
const int Rx_pin = A0;
const int Ry_pin = A1;
const int sw_pin = 2;

//* define the 4 switch button pins
const int left_pin  = 13;
const int right_pin = 12;
const int jump_pin  = 8;
const int pr_pin    = 7;

//*** led pin for test
const int ledPin = 2;

//* define x, y, sw vars
int x,
    y,
    sw;
//* define the 4 moves vars
int left,
    right,
    jump,
    pr;

char lcdTxt[17] = "youssef";

//* define the input delay
int dt = 500;


void setup() {
    //* set the serial part
    Serial.begin(9600);

    //* init the lcd
    lcd.init();
    lcd.backlight();

    //! testing part
    lcd.setCursor(16, 0);

    lcd.print(lcdTxt);

    lcd.setCursor(16, 1);

    lcd.print("7alawa :°");

    //* set Rx_pin, Ry_pin, sw_pin in INPUT mode
    pinMode(Rx_pin, INPUT);
    pinMode(Ry_pin, INPUT);
    pinMode(sw_pin, INPUT);

    //* set Rx_pin, Ry_pin, sw_pin in INPUT mode
    pinMode(left_pin,  INPUT);
    pinMode(right_pin, INPUT);
    pinMode(jump_pin,  INPUT);
    pinMode(pr_pin,    INPUT);

    //* set sw_pin in HIGH mode
    digitalWrite(sw_pin, HIGH);

    //*** ledPin
    pinMode(ledPin, OUTPUT);
}

void loop() {
    //* scroll the lcd txt to the left
    lcd.scrollDisplayLeft();

    //* detect the Rx_pin actions
    x  = analogRead(Rx_pin);

    //* detect the Ry_pin actions
    y  = analogRead(Ry_pin);

    //* detect the sw_pin actions
    sw = digitalRead(sw_pin);

    //* detect the 4 moves actions
    left  = digitalRead(left_pin);
    right = digitalRead(right_pin);
    jump  = digitalRead(jump_pin);
    pr    = digitalRead(pr_pin);

    digitalWrite(ledPin, left);

    //* test the execution of the joystick
    /*
    Serial.print("X: ");
    Serial.print(x);
    Serial.print(" Y: ");
    Serial.print(y);
    Serial.print(" SWITCH: ");
    Serial.println(sw);
    */

    //* test the execution of the 4 mvs buttons
    Serial.print("left: ");
    Serial.println(left);

    delay(dt);
}
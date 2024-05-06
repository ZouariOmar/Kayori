/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @author: zouari_omar
* @update: 04//24
? @file:   controller.ino
----------------------------------------------- */

//? ----------------------- NOTE SECTION DECLARATION PART -----------------------
/*
* if we can use "Serial.begin(115200)", use it. it give a quick communication response
*/

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
#include <LiquidCrystal_I2C.h>

//? -------------- LCD MSG(S) PROTOTYPE DECLARATION PART --------------
#define LCD_MSG00  "Welcome To Hollow Vessels";

//* init the lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);

//? ------------------ PINS PROTOTYPE DECLARATION PART ------------------
//* define the Rx, Ry and switch_joystick_button pins
const int Rx_pin           = A0;
const int Ry_pin           = A1;
const int interaction_pin  = 2;

//* define the 3 mvs switch button pins
const int jump_pin         = 13;
const int dash_pin         = 12;
const int slide_pin        = 11;

//* define the pause/resume  switch button pin
const int pr_pin           = 10;

//? -------------- PUBLIC VARS PROTOTYPE DECLARATION PART --------------
//* define the R/L and the interaction vars
int right,
    left,
    interaction;

//* define the 3 moves vars
int jump,
    dash,
    slide;

//* define the pause/resume var
int pr;

//* define the input delay
int dt = 500;


//? ----------------------- FUNCTIONS PROTOTYPE DEV PART -----------------------
void setup() {
    //* set the serial seed
    Serial.begin(9600);

    //* init the lcd
    lcd.init();
    lcd.backlight();

    //* set Rx_pin, Ry_pin, interaction_pin in INPUT mode
    pinMode(Rx_pin,          INPUT);
    pinMode(Ry_pin,          INPUT);
    pinMode(interaction_pin, INPUT);

    //* set Rx_pin, Ry_pin, interaction_pin in INPUT mode
    pinMode(jump_pin,   INPUT);
    pinMode(dash_pin,   INPUT);
    pinMode(slide_pin,  INPUT);

    //* set the pr_pin in INPUT mode
    pinMode(pr_pin,     INPUT);

    //* set interaction_pin in HIGH mode
    digitalWrite(interaction_pin, HIGH);
}

void loop() {
    //* scroll the lcd txt to the left
    //lcd.scrollDisplayLeft();

    //* detect the Rx_pin actions
    //x = analogRead(Rx_pin);

    //* detect the Ry_pin actions
    //y = analogRead(Ry_pin);

    //! testing part
    int direction;

    //* detect the interaction_pin actions
    interaction = digitalRead(interaction_pin);

    //* detect the 3 moves actions
    jump  = digitalRead(jump_pin);
    dash  = digitalRead(dash_pin);
    slide = digitalRead(slide_pin);

    //* detect the pause/resume actions
    pr = digitalRead(pr_pin);

    //* test the execution of the joystick
    /*
    Serial.print("X: ");
    Serial.print(x);
    Serial.print(" Y: ");
    Serial.print(y);
    Serial.print(" SWITCH: ");
    Serial.println(sw);
    */

    delay(dt);
}
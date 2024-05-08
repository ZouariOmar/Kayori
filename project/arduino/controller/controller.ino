/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @author: zouari_omar
* @update: 04//24
? @file:   controller.ino
----------------------------------------------- */

//? ----------------------- NOTE SECTION DECLARATION PART -----------------------
/*
* if we can use "Serial.begin(115200)", use it. it give a quick communication response
! we don't use the switch_joystick_button
*/

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
#include <LiquidCrystal_I2C.h>

//? -------------- LCD MSG(S) PROTOTYPE DECLARATION PART --------------
#define LCD_MSG00  "Welcome To Hollow Vessels"

//* init the lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);

//? ------------------ PINS PROTOTYPE DECLARATION PART ------------------
//* define the Rx, Ry pins
const int Rx_pin           = A0;
const int Ry_pin           = A1;

//* define the 2 mvs switch button pins
const int jump_pin         = 13;
const int dash_pin         = 12;

//* define the interaction switch button pin
const int interaction_pin  = 11;

//* define the pause/resume  switch button pin
const int pr_pin           = 10;

//? -------------- PUBLIC VARS PROTOTYPE DECLARATION PART --------------
//* define the X/Y vars
int x,
    y;

//* define the input delay
int dt = 500;


//? ----------------------- FUNCTIONS PROTOTYPE DEV PART -----------------------
void setup() {
    //* set the @serial_monitor_reading_speed
    Serial.begin(9600);

    //? -- init the LCD --
    lcd.init();
    lcd.backlight();

    //? -- INPUT pins mode declaration part --
    //* set Rx_pin, Ry_pin in IM
    pinMode(Rx_pin,          INPUT);
    pinMode(Ry_pin,          INPUT);

    //* set Rx_pin, Ry_pin in IM
    pinMode(jump_pin,        INPUT_PULLUP);
    pinMode(dash_pin,        INPUT_PULLUP);

    //* set the interaction_pin in IM
    pinMode(interaction_pin, INPUT_PULLUP);

    //* set the pr_pin in IM
    pinMode(pr_pin,          INPUT_PULLUP);

    //* set interaction_pin in HIGH read mode
    digitalWrite(interaction_pin, HIGH);

    lcd.setCursor(0, 0);
    lcd.print(LCD_MSG00);
}

void loop() {
    //* scroll the lcd txt to the left
    lcd.scrollDisplayLeft();

    //* detect the @joystick_directions using the Rx/Ry pins (8 direction)
    x = analogRead(Rx_pin);

    //* detect the Ry_pin actions
    y = analogRead(Ry_pin);

    ////Serial.println(x, y);

    //* detect the 2 moves pins actions    :: active in LOW mode
    if (!digitalRead(jump_pin))
        Serial.println("is_jump");

    if (!digitalRead(dash_pin))
        Serial.println("is_dash");

    //* detect the interaction_pin actions :: active in LOW mode
    if (!digitalRead(interaction_pin))
        Serial.println("is_interact");

    //* detect the pr_pin actions          :: active in LOW mode
    if (!digitalRead(pr_pin))
        Serial.println("is_pause");

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
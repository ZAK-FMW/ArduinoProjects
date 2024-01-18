#include <LiquidCrystal_I2C.h>

const int PX = A0;
const int PY = A1;
const int PSW = 6;

int ValueX;
int ValueY;
int ValueSW;

LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  pinMode(PX, INPUT);
  pinMode(PY, INPUT);
  pinMode(PSW, INPUT_PULLUP);
  Serial.begin(9600); // BAUD
}

void loop() {
  // put your main code here, to run repeatedly:
  JoystickLesen();
  lcd.setCursor(0,0);
  lcd.print("X: ");
  lcd.print(ValueX);
  lcd.setCursor(0,1);
  lcd.print("Y: ");
  lcd.print(ValueY);
  lcd.setCursor(0,2);
  lcd.print("SWITCH: ");
  lcd.print(ValueSW);
  delay(30);
  //lcd.clear();

}

void JoystickLesen(){
  ValueX = analogRead(PX);
  ValueY = analogRead(PY);
  ValueSW = digitalRead(PSW) != 1;
  Serial.print("X: ");
  Serial.print(ValueX);
  Serial.print(" Y: ");
  Serial.print(ValueY);
  Serial.print(" SW: ");
  Serial.println(ValueSW);
}
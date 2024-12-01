#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#define sensor A1
#define led 13
#define motor A0
//.................................................
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);

}
//.................................................
void loop() {
  int value = analogRead(sensor);
  value = map(value, 0, 823, 100, 0);
    lcd.setCursor(0, 0);
  lcd.print("Do am:        %");
  lcd.setCursor(8, 0);
  lcd.print(value);
  delay(100);
  if (value > 70) {
    Serial.println("Do am binh thuong");
    lcd.setCursor(0, 1);
    lcd.print("  DO AM DAT OK  ");
    digitalWrite(led, LOW);
    digitalWrite(motor, LOW);
  }
  else {
    Serial.println("Dat kho thieu nuoc");
    lcd.setCursor(0, 1);
    lcd.print("   THIEU NUOC   ");
    digitalWrite(led, HIGH);
    digitalWrite(motor, HIGH);
  }
}

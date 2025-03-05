#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#define sensor A1
#define led 13
#define motor A0
long time =0;
//.................................................
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
time = millis();
}
//.................................................
void loop() {
  int value = analogRead(sensor);
  Serial.println(value);
  value = map(value, 300, 1024, 100, 0);
  if(value >=100)value=100;
  if(value <=0)value=0;
  Serial.println(value);
    lcd.setCursor(0, 0);
  lcd.print("DO AM:       %");
  lcd.setCursor(8, 0);
  lcd.print(value);
  delay(100);
  if (value > 70) {
    Serial.println("Do am binh thuong");
    lcd.setCursor(0, 1);
    lcd.print(" DO AM DAT OK ");
    digitalWrite(led, LOW);
    digitalWrite(motor, LOW);
    time = millis();
  }
  else {
    Serial.println("Dat kho thieu nuoc");
    lcd.setCursor(0, 1);
    lcd.print("DAT THIEU NUOC");
    if(millis() - time <= 5000){
      digitalWrite(led, HIGH);
    digitalWrite(motor, HIGH);
    }
    else {
      digitalWrite(led, LOW);
    digitalWrite(motor, LOW);
    }
  }
}

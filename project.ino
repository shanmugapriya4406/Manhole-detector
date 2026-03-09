#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Sensor Pins
#define GAS_SENSOR A0
#define WATER_SENSOR A1
#define IR_SENSOR 7
#define BUZZER 8
#define DHTPIN 4
#define DHTTYPE DHT11

int gasThreshold = 400;
int waterThreshold = 500;

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);

  pinMode(IR_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.init();
  lcd.backlight();
  dht.begin();

  lcd.setCursor(0,0);
  lcd.print("Manhole Monitor");
  lcd.setCursor(0,1);
  lcd.print("System Start...");
  delay(2000);
}

void loop()
{
  int gasValue = analogRead(GAS_SENSOR);
  int waterValue = analogRead(WATER_SENSOR);
  int coverStatus = digitalRead(IR_SENSOR);
  float humidity = dht.readHumidity();

  if (isnan(humidity)) humidity = 0;

  Serial.print("Gas: ");
  Serial.println(gasValue);

  Serial.print("Water: ");
  Serial.println(waterValue);

  Serial.print("Humidity: ");
  Serial.println(humidity);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Gas:");
  lcd.print(gasValue);

  lcd.setCursor(0,1);
  lcd.print("Water:");
  lcd.print(waterValue);

  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hum:");
  lcd.print(humidity);

  lcd.setCursor(0,1);
  lcd.print("Cover:");
  lcd.print(coverStatus == LOW ? "OPEN" : "CLOSED");

  delay(2000);

  if(gasValue > gasThreshold)
  {
    lcd.clear();
    lcd.print("Gas Detected!");
    digitalWrite(BUZZER, HIGH);
  }
  else if(waterValue > waterThreshold)
  {
    lcd.clear();
    lcd.print("Water High!");
    digitalWrite(BUZZER, HIGH);
  }
  else if(coverStatus == LOW)
  {
    lcd.clear();
    lcd.print("Cover Open!");
    digitalWrite(BUZZER, HIGH);
  }
  else
  {
    digitalWrite(BUZZER, LOW);
  }

  delay(1000);
}
#include <Arduino.h>
#include <AM2320_asukiaaa.h>
#include <ST7032_asukiaaa.h>

AM2320_asukiaaa sensor;
ST7032_asukiaaa lcd;

void setup() {
  lcd.begin(8, 2);
  lcd.setContrast(30);
}

void loop() {
  lcd.clear();
  if (sensor.update() != 0) {
    Serial.println("Cannot read value from sensor.");
    lcd.setCursor(0, 0);
    lcd.print("error");
  } else {
    Serial.println("TemperatureC: " + String(sensor.temperatureC));
    Serial.println("Humidity: " + String(sensor.humidity));
    lcd.setCursor(0, 0);
    lcd.print(sensor.temperatureC);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print(sensor.humidity);
    lcd.print("%");
  }
  delay(1000);
}

#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

#define ONE_WIRE_BUS PB5
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celcius=0;

const int rs = PA4, en = PA5, d4 = PA0, d5 = PA1, d6 = PA2, d7 = PA3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  sensors.begin();
  lcd.begin(16, 2);           //Tamaño del LCD 16x2
  pinMode(PA6, OUTPUT);
  pinMode(PC13, OUTPUT);
}

void loop(void)
{ 
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  lcd.setCursor(0,0);
  lcd.print("STM32duino 2018");
  lcd.setCursor(0,1);
  lcd.print("DS18B20: ");
  lcd.print(Celcius);
  lcd.write(0xDF);
  lcd.print("C");
  delay(500);
}

#include <LiquidCrystal.h>

const int rs = PA4, en = PA5, d4 = PA0, d5 = PA1, d6 = PA2, d7 = PA3;
int contador = 0;
int deccont = 0;
int unicont = 0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);           //Tamaño del LCD 16x2
  pinMode(PA6, OUTPUT);
  pinMode(PC13, OUTPUT);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Kalun Lau Gan "); //Imprime el mensaje 
  digitizer();
  lcd.print(deccont, DEC);
  lcd.print(unicont, DEC);
  lcd.setCursor(0,1);
  lcd.print("STM32duino Test");
  digitalWrite(PA6, HIGH);
  digitalWrite(PC13, HIGH);
  delay(100);
  digitalWrite(PA6, LOW);
  digitalWrite(PC13, LOW);
  delay(100);
  if(contador > 98){
    contador = 0;
  }
  else{
    contador = contador +1;
  }
}

void digitizer()  {
  deccont = contador / 10;
  unicont = contador - (deccont * 10);
}


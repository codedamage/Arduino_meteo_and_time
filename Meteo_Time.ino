#include <virtuabotixRTC.h> //Library used
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> // Подключение библиотеки
#include <iarduino_RTC.h>
#include "DHT.h"       // подключаем библиотеку для датчика
// Порты экрана - А4, А5
DHT dht(7, DHT11); // сообщаем на каком порту будет датчик
LiquidCrystal_I2C lcd(0x27,16,2); // Указываем I2C адрес (наиболее распространенное значение), а также параметры экрана (в случае LCD 1602 - 2 строки по 16 символов в каждой 
iarduino_RTC time(RTC_DS1302, 2, 4, 3); //Порты таймера, в порядке RST, CLK, DAT

void setup()
{
//  time.begin(RTC_DS1302,2, 3, 4);
  
  
  time.begin();
  time.settime(10,20,01,13,06,19,4); 
  
  
  lcd.begin();                      // Инициализация дисплея  
  dht.begin();
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  lcd.backlight();                 // Подключение подсветки
  

}
void loop()
{
  
  delay(1000);
  float t = dht.readTemperature();
  float h = dht.readHumidity();
    lcd.setCursor(0,0);              // Установка курсора в начало первой строки
  lcd.print("t:");       // Набор текста на первой строке
  lcd.print(t); 
  lcd.print(" h:");       
  lcd.print(h); 
  
  lcd.setCursor(0,1);              // Установка курсора в начало второй строки
  lcd.print(time.gettime("H:i:s, d.m"));    // Набор текста на второй строке
  
  
}

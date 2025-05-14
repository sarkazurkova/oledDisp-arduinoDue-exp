#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);


void setup(void) {
  u8g2.begin();
  randomSeed(analogRead(A0));
  Serial.begin(9600);
}

String chooseRandomWord() {
  String words[]={"fish", "sun", "cat", "hello", "PC", "tea", "game", "arduino", "clock", "USB"};
  int n = random(0, sizeof(words) / sizeof(words[0]));
  return words[n];
}

void loadingScreen(){
  /*Displays moving loading text*/
  int j = 0;
  for(int i = 10; i < 70; i+=10){
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(j,i,"LOADING...");
    //Serial.print("loading... ");
    u8g2.sendBuffer();
    delay(1000);
    j+=11;
  }
}

void helloScreen(){
  /*Displays hello on the display*/
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(40,40,"Hello.");
  u8g2.sendBuffer();
  delay(3000);
}

void displayRandomWord(){
  String rWord = chooseRandomWord();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(45,40,rWord.c_str());
  Serial.println(rWord);
  u8g2.sendBuffer();
  delay(3000);
}

void loop(void) {
  Serial.print("loading... ");
  loadingScreen();  
  displayRandomWord();
}

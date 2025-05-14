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
  /*Displays moving text LOADING...*/
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
  /*Displays Hello, world! on the display*/
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(35,40,"Hello, world!");
  u8g2.sendBuffer();
  delay(3000);
}

void displayRandomWord(){
  /*Chooses from array 'words[]' a random word and displays it on display*/
  String rWord = chooseRandomWord();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(45,40,rWord.c_str());
  Serial.println(rWord); //print to console the selected word
  u8g2.sendBuffer();
  delay(3000);
}
 
void loop(void) {
  /*Main*/
  Serial.print("loading... ");
  loadingScreen();  
  displayRandomWord();
}

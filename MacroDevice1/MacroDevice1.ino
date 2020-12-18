#include <Bounce2.h>
#include "Buttons.h"
#include <Keyboard.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>


#define TFT_CS     A0
#define TFT_RST    A1  
#define TFT_DC     A2

#define REDRAW     11


int totalAPP = 4;
enum APP {
  chrome,
  altium,
  mcuxpressoide,
  iar
};

APP currentAPP = chrome;

// For 1.44" and 1.8" TFT with ST7735 use
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

int margin = 10;
int squareWidth = 0;
int squareHeight = 0;

Bounce debounce1 = Bounce();
Bounce debounce2 = Bounce();
Bounce debounce3 = Bounce();
Bounce debounce4 = Bounce();
Bounce debounce5 = Bounce();
Bounce debounce6 = Bounce();
Bounce debounce7 = Bounce();
Bounce debounce8 = Bounce();
Bounce debounce9 = Bounce();

Buttons button = Buttons();

void setup() {

  pinMode(2, INPUT_PULLUP);
  debounce1.attach(2);
  debounce1.interval(5);
  pinMode(3, INPUT_PULLUP);
  debounce2.attach(3);
  debounce2.interval(5);
  pinMode(4, INPUT_PULLUP);
  debounce3.attach(4);
  debounce3.interval(5);
  pinMode(5, INPUT_PULLUP);
  debounce4.attach(5);
  debounce4.interval(5);
  pinMode(6, INPUT_PULLUP);
  debounce5.attach(6);
  debounce5.interval(5); 
  pinMode(7, INPUT_PULLUP);
  debounce6.attach(7);
  debounce6.interval(5);
  pinMode(8, INPUT_PULLUP);
  debounce7.attach(8);
  debounce7.interval(5);
  pinMode(9, INPUT_PULLUP);
  debounce8.attach(9);
  debounce8.interval(5);
  pinMode(10, INPUT_PULLUP);
  debounce9.attach(10);
  debounce9.interval(5);

    Serial.begin(115200);
  // Use this initializer if you're using a 1.8" TFT
  tft.initR(INITR_GREENTAB);   // initialize a ST7735S chip, black tab
  //Rotate so SPI TFT is on bottom
  tft.setRotation(3);
  //Clear screen
  tft.fillScreen(ST77XX_RED);
  //draw each button space
  drawSquares(ST77XX_WHITE);
  //define square size
  squareWidth = tft.width()/3;
  squareHeight = tft.height()/3;

  printSquare("New Tab",3,ST77XX_WHITE);
  printSquare("Digikey",2,ST77XX_WHITE);
  printSquare("Close",1,ST77XX_WHITE);
  printSquare("BC",6,ST77XX_WHITE);
  printSquare("Refresh",5,ST77XX_WHITE);
  printSquare("Last",4,ST77XX_WHITE);
  printSquare("For",9,ST77XX_WHITE);
  printSquare("Prev",8,ST77XX_WHITE);
  printSquare("N App",7,ST77XX_WHITE);
  setTitle("Chrome",ST77XX_WHITE); 

//  tft.fillScreen(ST77XX_RED);
//  drawSquares(ST77XX_WHITE);

  Keyboard.begin();
}

void loop() 
{
  
   CheckButtons();
   //CheckActiveWindow();

}

void CheckActiveWindow()
{
  if (Serial.available() > 0) {
      int pos = Serial.parseInt();

      CheckCommands(pos);

      if(pos<10)
      {
        while(Serial.available() ==0){}
        String phrase = Serial.readString();
        if(pos == 10)
        {
          setTitle(phrase,ST77XX_WHITE);
        }
        else
        {
          printSquare(phrase,pos,ST77XX_WHITE);          
        }
      }
    }
}

void CheckCommands(int pos)
{
  if(pos == 11)
  {
    tft.fillScreen(ST77XX_BLUE);
    drawSquares(ST77XX_BLACK);
  }
}

void changeApp(APP newAPP)
{
  currentAPP =newAPP;
  switch(newAPP){
    case chrome:
      tft.fillScreen(ST77XX_RED);
      //draw each button space
      drawSquares(ST77XX_WHITE);
      printSquare("FOR Tab",3,ST77XX_WHITE);
      printSquare("PREV Tab",2,ST77XX_WHITE);
      printSquare("Close",1,ST77XX_WHITE);
      printSquare("New Tab",6,ST77XX_WHITE);
      printSquare("Refresh",5,ST77XX_WHITE);
      printSquare("Last",4,ST77XX_WHITE);
      printSquare("For D",9,ST77XX_WHITE);
      printSquare("Prev D",8,ST77XX_WHITE);
      printSquare("N App",7,ST77XX_WHITE);
      setTitle("Chrome",ST77XX_WHITE); 
      setTitle("Chrome",ST77XX_WHITE); 
      break;
    case altium:
      tft.fillScreen(ST77XX_WHITE);
      //draw each button space
      drawSquares(ST7735_BLUE);
      setTitle("Altium",ST7735_BLUE);
      printSquare("Trace",3,ST77XX_BLACK);
      printSquare("NSignal",9,ST77XX_BLACK);
      printSquare("R Error",2,ST77XX_BLACK);
      printSquare("+S",5,ST77XX_BLACK);
      printSquare("Sw Lay",6,ST77XX_BLACK);
      printSquare("DesignR",1,ST77XX_BLACK); 
      printSquare("Wire",8,ST77XX_BLACK);
      break;
    case mcuxpressoide:
      tft.fillScreen(ST77XX_YELLOW);
      //draw each button space
      drawSquares(ST77XX_WHITE);
      setTitle("MCUExpresso",ST77XX_WHITE);
      printSquare("Clean",1,ST77XX_BLACK);
      printSquare("Build",2,ST77XX_BLACK);
      printSquare("Debug",3,ST77XX_BLACK);
      printSquare("For L",4,ST77XX_BLACK);
      printSquare("S Debug",5,ST77XX_BLACK);
      printSquare("Run",6,ST77XX_BLACK);
      printSquare("N App",7,ST77XX_BLACK);
      printSquare("Comment",8,ST77XX_BLACK);
      printSquare("Step O",9,ST77XX_BLACK);
      break;
   case iar:
      tft.fillScreen(ST77XX_BLACK);
      //draw each button space
      drawSquares(ST77XX_BLUE);
      setTitle("IAR",ST77XX_WHITE);
      printSquare("Back",1,ST77XX_WHITE);
      printSquare("Make",2,ST77XX_WHITE);
      printSquare("Debug",3,ST77XX_WHITE);
      printSquare("Go to D",4,ST77XX_WHITE);
      printSquare("S Debug",5,ST77XX_WHITE);
      printSquare("Run",6,ST77XX_WHITE);
      printSquare("N App",7,ST77XX_WHITE);
      printSquare("Comment",8,ST77XX_WHITE);
      printSquare("Step O",9,ST77XX_WHITE);
      break;
      
  }
  if(currentAPP == totalAPP-1)
    currentAPP =-1;
}

void printSquare(String text,int square,uint16_t color)
{
  int y = 0;
  int x = 0;
  int yspace = 0;
  int xspace = 0;

  switch(square){
    case 1:
      yspace = 0;
      xspace = 0;
      break;
    case 2:
      yspace = 0;
      xspace = 1;
      break;
    case 3:
      yspace = 0;
      xspace = 2;
      break;
    case 4:
      yspace = 1;
      xspace = 0;
      break;
    case 5:
      yspace = 1;
      xspace = 1;
      break;
    case 6:
      yspace = 1;
      xspace = 2;
      break;
    case 7:
      yspace = 2;
      xspace = 0;
      break;
    case 8:
      yspace = 2;
      xspace = 1;
      break;
    case 9:
      yspace = 2;
      xspace = 2;
      break;
  }
  if(square == 10)
  {
    tft.setCursor(tft.width()/2-20,0);
    tft.setTextSize(1);
    tft.setTextColor(color);
    tft.print(text);
  }
  else
  {
    x = (squareWidth*xspace) + margin;
    y = (squareHeight*yspace) + margin;
    tft.setCursor(x,y);
  
    tft.setTextColor(color);
    tft.setTextWrap(true);
    tft.print(text);
  }
}

void drawSquares(uint16_t color)
{
  //Vertical Lines
  tft.drawLine(tft.width()/3, 0, tft.width()/3, tft.height()-1, color);
  tft.drawLine((tft.width()/3)*2, 0, (tft.width()/3)*2, tft.height()-1, color);
  //Horizontal Lines
  tft.drawLine(0,tft.height()/3,tft.width(), tft.height()/3, color);
  tft.drawLine(0,(tft.height()/3)*2,tft.width(),(tft.height()/3)*2, color);
}

void setTitle(String title,uint16_t color)
{
  tft.setCursor(tft.width()/2-20,0);
  tft.setTextSize(1);
  tft.setTextColor(color);
  tft.print(title);
}
void CheckButtons()
{
    debounce1.update();
  bool value = debounce1.fell();
  if(value ==1)
    button.ServiceButton1();
    //Serial.println("1");

    debounce2.update();
  bool value2 = debounce2.fell();
  if(value2 ==1)
    button.ServiceButton2();

    debounce3.update();
  bool value3 = debounce3.fell();
  if(value3 ==1)
    button.ServiceButton3();

    debounce4.update();
  bool value4 = debounce4.fell();
  if(value4 ==1)
    button.ServiceButton4();

    debounce5.update();
  bool value5 = debounce5.fell();
  if(value5 ==1)
    button.ServiceButton5();

    debounce6.update();
  bool value6 = debounce6.fell();
  if(value6 ==1)
    button.ServiceButton6();

    debounce7.update();
  bool value7 = debounce7.fell();
  if(value7 ==1)
    button.ServiceButton7();

    debounce8.update();
  bool value8 = debounce8.fell();
  if(value8 ==1)
    button.ServiceButton8();

    debounce9.update();
  bool value9 = debounce9.fell();
  if(value9 ==1)
    {    
//      tft.fillScreen(ST77XX_RED);
//      drawSquares(ST77XX_WHITE);
      value9=0;
      currentAPP = currentAPP +1;
      changeApp(currentAPP);
      delay(200);
      int val = digitalRead(10); 
      Serial.print("value = ");
      Serial.println(val);
      if(val==0)
      {
        button.ServiceButton9();
      }
    }
    
}

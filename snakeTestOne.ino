#include <LedControl.h>

int DIN = 2;
int CS = 3;
int CLK = 4;

const int length = 8;
const int height = 8;

const boolean screenOrPrint = true;

boolean pixels[ length ][ height ];

LedControl screen= LedControl(DIN, CLK, CS, 0);

void screenUpdate(){
  if (screenOrPrint == true){
    for (int i = 0; i < length; i++){
      for (int ii = 0; ii < height; ii++){
        if (pixels[i][ii] == true){
          screen.setLed(0, i, ii, true);
        }
        if (pixels[i][ii] == false){
          screen.setLed(0, i, ii, false);
        }
      }
    }
  }
  if (screenOrPrint == false){
    for (int i = 0; i < length; i++){
      for (int ii = 0; ii < height; ii++){
        if (pixels[ii][i] == true){
          Serial.print("[#]");
        }
        if (pixels[ii][i] == false){
          Serial.print("[ ]");
        }
      }
    Serial.println("\n");
    }
    Serial.println("\n\n");
  delay(2000);
  }
}

void testAll(){
  for (int i = 0; i < 8; i++){
    for (int ii = 0; ii < 8; ii++){
      pixels[i][ii] = true;
      delay(1);
      screenUpdate();
    }
  }
  delay(2000);
  
  for (int i = 0; i < 8; i++){
    for (int ii = 0; ii < 8; ii++){
      pixels[i][ii] = false;
      delay(1);
      screenUpdate();
    }
  }
  delay(2000);
}
void clearDisplay(){
  for (int i = 0; i < 8; i++){
    for (int ii = 0; ii < 8; ii++){
      pixels[i][ii] = false;
    }
  }
}

void setup(){
  screen.shutdown(0,false);
  screen.setIntensity(0, 15);
  clearDisplay();
  Serial.begin(115200);
  screenUpdate();
}
void snaketest(int xIN, int yIN){
  pixels[xIN][yIN] = true;
  screenUpdate();
  // clearDisplay();
}
String snakePath = "uururrdrdddddddlrldduuruuurdllluul";
void loop(){
  clearDisplay();
  delay(1000);
  int x = 1;
  int y = 5;
  snaketest(x,y);
  delay(1000);
  for(int i = 0; i < snakePath.length(); i++){
    char sCase = snakePath.charAt(i);
    switch ((char)sCase){
      case 'u':
        if(y + 1 > 7){
          Serial.println("kan niet/dood");
          break;
        } else{
          y += 1;
          break;
        }
      case 'd':
        if(y - 1 < 0){
          Serial.println("kan niet/dood");
          break;
        } else{
          y -= 1;
          break;
        }
      case 'r':
        if(x + 1 > 7){
          Serial.println("kan niet/dood");
          break;
        } else{
          x += 1;
          break;
        }
      case 'l':
        if(x - 1 < 0){
          Serial.println("kan niet/dood");
          break;
        } else{
          x -= 1;
          break;
        }
    }
    snaketest(x,y);
    delay(500);
  }
}
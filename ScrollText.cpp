/*
Library for displaying scrolling text on a single seven segment display.
Supports characters A-Z (mixed case) and digits 0-9. Also included is an underscore and blank (256).
Author: Thomas Lee
*/

#include <string.h>

#include "WProgram.h"
#include "ScrollText.h"

//Define pins on instantiation
ScrollText::ScrollText(int latchPin, int clockPin, int dataPin) {
  pinMode(latchPin, OUTPUT);
  _latchPin=latchPin;
  pinMode(clockPin, OUTPUT);
  _clockPin=clockPin;
  pinMode(dataPin, OUTPUT);
  _dataPin=dataPin;
}

//Replace all of one occurance of a character with another character in a string 
char* ScrollText::replaceAll(char text[], char charToReplace, char charReplacement) {
  int i;
  for (i=0; i<strlen(text); i++) {
    if (text[i] == charToReplace) {
      text[i] = charReplacement;
    }
  }
  delay(1); //I have no idea why this is necessary, but it is.
  return text;
}

char* ScrollText::intToString(int number) {
  char str[maxIntDigits];  
  return itoa(number, str, 10);
}

//Display the characters in the string taken as an argument one by one for the default time each.
void ScrollText::scrollText(char text[]) {
  text = replaceAll(text, 32, '_');
  int i;
  for (i=0; i<strlen(text); i++) {
    dispChar(text[i]);
    delay(defaultTime);
    dispChar(blank);
    delay(betweenLetters);
  }
  dispChar(blank);
}

//Display the characters in the string taken as an argument one by one for the default time each, giving the option to match case
void ScrollText::scrollText(char text[], bool matchCase) {
  text = replaceAll(text, 32, '_');
  int i;
  for (i=0; i<strlen(text); i++) {
    dispChar(text[i], matchCase);
    delay(defaultTime);
    dispChar(blank);
    delay(betweenLetters);
  }
  dispChar(blank);
}

//Display the characters in the string taken as an argument one by one for the specified number of milliseconds each.
void ScrollText::scrollText(char text[], int duration) {
  text = replaceAll(text, 32, '_');
  int i;
  for (i=0; i<strlen(text); i++) {
    dispChar(text[i]);
    delay(duration);
    dispChar(blank);
    delay(betweenLetters);
  }
  dispChar(blank);
}

//Display the characters in the string taken as an argument one by one for the specified number of milliseconds each, giving the option to match case.
void ScrollText::scrollText(char text[], int duration, bool matchCase) {
  text = replaceAll(text, 32, '_');
  int i;
  for (i=0; i<strlen(text); i++) {
    dispChar(text[i], matchCase);
    delay(duration);
    dispChar(blank);
    delay(betweenLetters);
  }
  dispChar(blank);
}

//Display the numbers in the array taken as an argument one by one for the specified number of milliseconds each.
void ScrollText::scrollText(int num, int duration) {
  int i;
  char newNum[maxIntDigits] = "";
  strcpy(newNum, intToString(num));
  for (i=0; i<strlen(newNum); i++) {
    dispChar(newNum[i]);
    delay(duration);
    dispChar(blank);
    delay(betweenLetters);
  }
  dispChar(blank);
}

//Display the numbers in the array taken as an argument one by one for the default time.
void ScrollText::scrollText(int num) {
  int i;
  char newNum[maxIntDigits] = "";
  strcpy(newNum, intToString(num));
  for (i=0; i<strlen(newNum); i++) {
    dispChar(newNum[i]);
    delay(defaultTime);
    dispChar(blank);
    delay(betweenLetters);
  }
  dispChar(blank);
}

//Display a single character on the seven segment display
void ScrollText::dispChar(int digit) {
  char b = B00000000;
  if (digit == blank) {
    b = dispBlank;
  } else {
    //Letters
    switch (digit) {
      case 'a':
      case 'A':
        b = dispA;
        break;
      case 'b':
      case 'B':
        b = dispB;
        break;
      case 'c':
      case 'C':
        b = dispC;
        break;
      case 'd':
      case 'D':
        b = dispD;
        break;
      case 'e':
      case 'E':
        b = dispE;
        break;
      case 'f':
      case 'F':
        b = dispF;
        break;
      case 'g':
      case 'G':
        b = dispG;
        break;
      case 'h':
      case 'H':
        b = dispH;
        break;
      case 'i':
      case 'I':
        b = dispI;
        break;
      case 'j':
      case 'J':
        b = dispJ;
        break;
      case 'k':
      case 'K':
        b = dispK;
        break;
      case 'l':
      case 'L':
        b = dispL;
        break;
      case 'm':
      case 'M':
        b = dispM;
        break;
      case 'n':
      case 'N':
        b = dispN;
        break;
      case 'o':
      case 'O':
        b = dispO;
        break;
      case 'p':
      case 'P':
        b = dispP;
        break;
      case 'q':
      case 'Q':
        b = dispQ;
        break;
      case 'r':
      case 'R':
        b = dispR;
        break;
      case 's':
      case 'S':
        b = dispS;
        break;
      case 't':
      case 'T':
        b = dispT;
        break;
      case 'u':
      case 'U':
        b = dispU;
        break;
      case 'v':
      case 'V':
        b = dispV;
        break;
      case 'w':
      case 'W':
        b = dispW;
        break;
      case 'x':
      case 'X':
        b = dispX;
        break;
      case 'y':
      case 'Y':
        b = dispY;
        break;
      case 'z':
      case 'Z':
        b = dispZ;
        break;
      case '_':
        b = disp_;
        break;
    }
    //Numbers
    switch (digit) {
      case 0: 
      case 48:
        b = disp0;
        break;
      case 1:
      case 49:
        b = disp1;
        break;
      case 2:
      case 50:
        b = disp2;
        break;
      case 3:
      case 51:
        b = disp3;
        break;
      case 4:
      case 52:
        b = disp4;
        break;
      case 5:
      case 53:
        b = disp5;
        break;
      case 6:
      case 54:
        b = disp6;
        break;
      case 7:
      case 55:
        b = disp7;
        break;
      case 8:
      case 56:
        b = disp8;
        break;
      case 9:
      case 57:
        b = disp9;
        break;
    }
  }
  putOnDisp(b);
}

//Display a single character on the seven segment display, with the option of matching case, might look better, but far more ambiguous.
void ScrollText::dispChar(int digit, bool matchCase) {
  char b = B00000000;
  if (digit == blank) {
    b = dispBlank;
  } else if (matchCase){
    //Letters
    switch (digit) {
      case 'a':
        b = dispA_L;
        break;
      case 'A':
        b = dispA_U;
        break;
      case 'b':
        b = dispB_L;
        break;
      case 'B':
        b = dispB_U;
        break;
      case 'c':
        b = dispC_L;
        break;
      case 'C':
        b = dispC_U;
        break;
      case 'd':
        b = dispD_L;
        break;
      case 'D':
        b = dispD_U;
        break;
      case 'e':
        b = dispE_L;
        break;
      case 'E':
        b = dispE_U;
        break;
      case 'f':
        b = dispF_L;
        break;
      case 'F':
        b = dispF_U;
        break;
      case 'g':
        b = dispG_L;
        break;
      case 'G':
        b = dispG_U;
        break;
      case 'h':
        b = dispH_L;
        break;
      case 'H':
        b = dispH_U;
        break;
      case 'i':
        b = dispI_L;
        break;
      case 'I':
        b = dispI_U;
        break;
      case 'j':
        b = dispJ_L;
        break;
      case 'J':
        b = dispJ_U;
        break;
      case 'k':
        b = dispK_L;
        break;
      case 'K':
        b = dispK_U;
        break;
      case 'l':
        b = dispL_L;
      break;
      case 'L':
        b = dispL_U;
        break;
      case 'm':
        b = dispM_L;
        break;
      case 'M':
        b = dispM_U;
        break;
      case 'n':
        b = dispN_L;
        break;
      case 'N':
        b = dispN_U;
        break;
      case 'o':
        b = dispO_L;
        break;
      case 'O':
        b = dispO_U;
        break;
      case 'p':
        b = dispP_L;
        break;
      case 'P':
        b = dispP_U;
        break;
      case 'q':
        b = dispQ_L;
        break;
      case 'Q':
        b = dispQ_U;
        break;
      case 'r':
        b = dispR_L;
        break;
      case 'R':
        b = dispR_U;
        break;
      case 's':
        b = dispS_L;
        break;
      case 'S':
        b = dispS_U;
        break;
      case 't':
        b = dispT_L;
        break;
      case 'T':
        b = dispT_U;
        break;
      case 'u':
        b = dispU_L;
        break;
      case 'U':
        b = dispU_U;
        break;
      case 'v':
        b = dispV_L;
        break;
      case 'V':
        b = dispV_U;
        break;
      case 'w':
        b = dispW_L;
        break;
      case 'W':
        b = dispW_U;
        break;
      case 'x':
        b = dispX_L;
        break;
      case 'X':
        b = dispX_U;
        break;
      case 'y':
        b = dispY_L;
        break;
      case 'Y':
        b = dispY_U;
        break;
      case 'z':
        b = dispZ_L;
        break;
      case 'Z':
        b = dispZ_U;
        break;
      case '_':
        b = disp_;
        break;
    }
    //Numbers
    switch (digit) {
      case 0: 
      case '0':
        b = disp0;
        break;
      case 1:
      case '1':
        b = disp1;
        break;
      case 2:
      case '2':
        b = disp2;
        break;
      case 3:
      case '3':
        b = disp3;
        break;
      case 4:
      case '4':
        b = disp4;
        break;
      case 5:
      case '5':
        b = disp5;
        break;
      case 6:
      case '6':
        b = disp6;
        break;
      case 7:
      case '7':
        b = disp7;
        break;
      case 8:
      case '8':
        b = disp8;
        break;
      case 9:
      case '9':
        b = disp9;
        break;
    }
  } else {
    dispChar(digit);
    return;
  }
  putOnDisp(b);
}

void ScrollText::putOnDisp(char b) {
  digitalWrite(_latchPin, LOW); 
  shiftOut(_dataPin, _clockPin, MSBFIRST, b);
  digitalWrite(_latchPin, HIGH);
}
/*
Library for displaying scrolling text on a single seven segment display.
Supports characters A-Z (mixed case) and digits 0-9. Also included is an underscore and blank.
Author: Thomas Lee
*/

#ifndef ScrollText_H
#define ScrollText_H

#include "WProgram.h"

class ScrollText {

  public:
    
    ScrollText(int latchPin, int clockPin, int dataPin);
  
    char* replaceAll(char text[], char charToReplace, char charReplacement);
    char* intToString(int num);
    
    //Yes, I really do like polymorphism
    
    void scrollText(char text[]);
    void scrollText(char text[], int duration);
    void scrollText(char text[], short int matchCase);
    void scrollText(char text[], int duration, short int matchCase);
    
    void scrollText(int num);
    void scrollText(int num, int duration);
    
    void dispChar(int digit);
    void dispChar(int digit, short int matchCase);
    
    void putOnDisp(char b);
  
  private: 
  
    // -- Start Of Character Definitions -- //

	  //Digits for 7seg display - Note that the dot (bit 1) is used to distinguish between letters and numbers
	  static const char disp0 = B01000000;
	  static const char disp1 = B01111001;
	  static const char disp2 = B00100100;
	  static const char disp3 = B00110000;
	  static const char disp4 = B00011001;
	  static const char disp5 = B00010010;
	  static const char disp6 = B00000010;
	  static const char disp7 = B01111000;
	  static const char disp8 = B00000000;
	  static const char disp9 = B00011000;

    //Letters for 7seg display (uppercase, somewhat ambiguous)
	  static const char dispA_U = B10001000;
	  static const char dispB_U = B10000000;
	  static const char dispC_U = B11000110;
	  static const char dispD_U = B11000000; //Same as O
	  static const char dispE_U = B10000110;
	  static const char dispF_U = B10001110;
	  static const char dispG_U = B11000010; //A bit odd
	  static const char dispH_U = B10001001; //Same as X
	  static const char dispI_U = B11111001; 
	  static const char dispJ_U = B11110001;
	  static const char dispK_U = B10001010; //Weird
	  static const char dispL_U = B11000111;
	  static const char dispM_U = B10101010; //Weird
	  static const char dispN_U = B11001000; //Impossible to do uppercase, just a massive n
	  static const char dispO_U = B11000000; //Same as D
	  static const char dispP_U = B10001100;
	  static const char dispQ_U = B10011000;
	  static const char dispR_U = B11001110; //Impossible to do uppercase properly, just a massive r
	  static const char dispS_U = B10010010;
	  static const char dispT_U = B10000111; //Impossible to do uppercase
	  static const char dispU_U = B11000101; 
	  static const char dispV_U = B10011101; //Weird, impossible to do uppercase
	  static const char dispW_U = B11100010; //Weird, impossible to do uppercase
	  static const char dispX_U = B10001001; //Same as H
	  static const char dispY_U = B10011001;
	  static const char dispZ_U = B10100100;
	  
	  //Letters for 7seg display (lowercase, somewhat ambiguous)
	  static const char dispA_L = B10100000;
	  static const char dispB_L = B10000011;
	  static const char dispC_L = B10100111;
	  static const char dispD_L = B10100001;
	  static const char dispE_L = B10000100;
	  static const char dispF_L = B10001110; //Impossible to do lowercase
	  static const char dispG_L = B10010000;
	  static const char dispH_L = B10001011;
	  static const char dispI_L = B11111011;
	  static const char dispJ_L = B11110011; //A bit odd
	  static const char dispK_L = B10001010; //Weird
	  static const char dispL_L = B11100111; //A bit odd
	  static const char dispM_L = B10101010; //Weird
	  static const char dispN_L = B10101011;
	  static const char dispO_L = B10100011;
	  static const char dispP_L = B10001100; //Impossible to do lowercase
	  static const char dispQ_L = B10011000; //Impossible to do lowercase
	  static const char dispR_L = B10101111;
	  static const char dispS_L = B10010010; //Impossible to do lowercase
	  static const char dispT_L = B10000111;
	  static const char dispU_L = B11100011; 
	  static const char dispV_L = B10011101; //Weird
	  static const char dispW_L = B11100010; //Weird
	  static const char dispX_L = B10001001; //Easily confused with H, but not the same
	  static const char dispY_L = B10010001;
	  static const char dispZ_L = B10100100; //Impossible to do lowercase

	  //Letters for 7seg display (mixed case, totally unambiguous, if occasionaly ugly)
	  //I realise this set simply duplicates the items in the two below, kept separate to make it easier to modify
	  static const char dispA = dispA_U;
	  static const char dispB = dispB_L;
	  static const char dispC = dispC_L;
	  static const char dispD = dispD_L;
	  static const char dispE = dispE_U;
	  static const char dispF = dispF_U;
	  static const char dispG = dispG_L;
	  static const char dispH = dispH_L;
	  static const char dispI = dispI_U;
	  static const char dispJ = dispJ_U;
	  static const char dispK = dispK_U; //Weird
	  static const char dispL = dispL_U;
	  static const char dispM = dispM_L; //Weird
	  static const char dispN = dispN_L;
	  static const char dispO = dispO_L;
	  static const char dispP = dispP_U;
	  static const char dispQ = dispQ_U;
	  static const char dispR = dispR_L;
	  static const char dispS = dispS_U;
	  static const char dispT = dispT_L;
	  static const char dispU = dispU_L; 
	  static const char dispV = dispV_L; //Weird
	  static const char dispW = dispW_L; //Weird
	  static const char dispX = dispX_L; //Easily confused with H, but not the same
	  static const char dispY = dispY_U;
	  static const char dispZ = dispZ_U;

	  //Special characters: underscore and blank
	  static const char disp_ = B11110111;
	  static const char dispBlank = B11111111;
	
    // -- End Of Character Definitions -- //
    
    //Used to make displaying blank on the 7seg display easier
    static const int blank = 256;
    
    //The maximum number of decimal digits that an integer may consist of.
    //20 allows for unsigned long long
    static const int maxIntDigits = 20;

    //The amount of delay between the letters (keep low)
    static const int betweenLetters = 50; //Milliseconds
    
    //The amount of time letters are shown for if time is not specified
    static const int defaultTime = 2000; //Milliseconds
    
    //All required pins
    int _latchPin;
    int _clockPin;
    int _dataPin;

};
#endif


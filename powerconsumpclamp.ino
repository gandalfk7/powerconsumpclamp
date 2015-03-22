/*

  PrintTest.pde
  
  How to use the base class "Print"
  
  >>> Before compiling: Please remove comment from the constructor of the 
  >>> connected graphics display (see below).
  
  Universal 8bit Graphics Library, http://code.google.com/p/u8glib/
  
  Copyright (c) 2012, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
  
*/


#include "U8glib.h"
int sensorPin = A0;
int sensorValue = 0;

U8GLIB_SSD1306_128X64 u8g(10, 9, 12, 11);

void setup(void) {
  // flip screen, if required
  // u8g.setRot180();
  pinMode(8, OUTPUT);
}

void loop(void) {
  // picture loop
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(8, LOW);
  
  float sensorValue = analogRead(sensorPin);
  float voltage= sensorValue * (5.0 / 1023.0); 
  float watt= voltage * (2200);
  String pwatt = "Watt: ";
  String symw = " W";
  String ppwatt = pwatt + watt + symw;
  
  String inval = "input val: ";
  String pinval = inval + sensorValue;
  
  String volt = "voltage: ";
  String symv = " V";
  String pvolt = volt + voltage + symv;
  
  String f1 = "F1:  ";
  String f2 = "F23: ";
  float costf1 = (watt / 1000) * 0.09076;
  float costf2 = (watt / 1000) * 0.08414;
  String syme = " euri/h";
  String pcostf1 = f1 + costf1 + syme;
  String pcostf2 = f2 + costf2 + syme;
  
  u8g.firstPage();  
  do {
    u8g.setFont(u8g_font_unifont);
    u8g.setPrintPos(0, 10);
    u8g.print(pinval);
    u8g.setPrintPos(0, 23);
    u8g.print(pvolt);
    u8g.setPrintPos(0, 36);
    u8g.print(ppwatt);
    u8g.setPrintPos(0, 48);
    u8g.print(pcostf1);
    u8g.setPrintPos(0, 60);
    u8g.print(pcostf2);
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(500);
}

#include "SlowSoftSerial.h"
  
  SlowSoftSerial sss(0,1);
  int baudIdx = 0;
  int buadRates[7] = {110, 300, 600, 1200, 2400, 4800, 9600};
  const char* buadRatesStr[7]= {"110", "300", "600", "1200", "2400", "4800", "9600"};
  
  void setup() {
    Serial.begin(115200);
    sss.begin(buadRates[baudIdx]);
  }
  
  void loop() {
      
    if (Serial.available()) 
    {      
      char c = Serial.read();
      
      if (c == 26 )
      {
        baudIdx = (baudIdx + 1) % 7;
       
        sss.end();
        sss.begin(buadRates[baudIdx]);
  
        Serial.println("");
        Serial.print("Setting baud to ");
        Serial.print(buadRatesStr[baudIdx]);
        Serial.println(".");
        
        return;
      }
      else 
      {
        sss.write(c);
      }
    }
    
    if (sss.available()) 
    {    
      char c = sss.read();
      Serial.write(c & 0b01111111);
    }
  }

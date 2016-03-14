#include <SPI.h> 
#include <RH_ASK.h>
#define MAX_MSG_LEN 59

RH_ASK fs1000a = RH_ASK(2000, 11, 12, 10, false);

void setup() {
    Serial.begin(9600);
  
    if (fs1000a.init()) Serial.println("Extremo TX. Init OK");
}

void loop() {
  fs1000a.send((uint8_t *)”A”, 2);
  fs1000a.waitPacketSent();
  delay(500);

  fs1000a.send((uint8_t *)”B”, 2);
  fs1000a.waitPacketSent();
  delay(500);
}

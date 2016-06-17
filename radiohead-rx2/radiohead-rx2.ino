#include <RH_ASK.h>
#define MAX_MSG_LEN 59

RH_ASK receptor = RH_ASK(2000, 11, 12, 10, false);

void setup() {
  Serial.begin(9600);
  if (receptor.init()) Serial.println("Extremo RX. Init OK");
}

void loop() {
  char msg[MAX_MSG_LEN+1];
  byte len = sizeof(msg);

  if (receptor.recv( (uint8_t*) msg, (uint8_t*) &len)) {
    for (byte i = 0; i < len; i++)
      Serial.print(msg[i]);
    Serial.println();
  }
} 

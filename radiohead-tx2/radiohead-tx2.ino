#include <SPI.h> 
#include <RH_ASK.h>
#define MAX_MSG_LEN 59

RH_ASK fs1000a = RH_ASK(2000, 11, 12, 10, false);

void setup() {
    Serial.begin(9600);
    
    if (fs1000a.init()) Serial.println("Extremo TX. Init OK");
}

void loop() {
  static int i=0;
  static char msg[MAX_MSG_LEN+1];
  
  if(Serial.available()) {
    if (i > MAX_MSG_LEN){
      Serial.println("Mensaje demasiado largo. Descartando...");
      i=0;
    }
    else{
      msg[i++]=Serial.read();
    }
  }
  
  if (msg[i-1] == '\n'){
    msg[i]='\0';
    i=0;
    
    fs1000a.send((uint8_t *)msg, strlen(msg));
    fs1000a.waitPacketSent();
    Serial.println("Enviado!");
  }
}

#include <IRremote.h>

IRsend emisorIR; //El pin de TX siempre debe ser el 3 (Definido en la librería)

void setup() {
  Serial.begin(9600);
}

void loop(){
  static unsigned long trama = 0x00;
  
  emisorIR.sendNEC(trama++ , 32);
  delay(100);
}

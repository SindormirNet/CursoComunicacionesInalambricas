#include <IRremote.h>
#define IR_RX A1

IRrecv receptorIR(IR_RX);
decode_results trama;

void setup() {
  Serial.begin(9600);
  receptorIR.enableIRIn();
}

void loop(){
  if (receptorIR .decode(&trama)) {
    if (trama.decode_type==3){
      Serial.print("Ha llegado: ");
      Serial.println(trama.value,HEX);
    }
    else{
      Serial.print("Mando tipo: ");
      Serial.print(trama.decode_type);
      Serial.print(" ha enviado ");
      Serial.println(trama.value,HEX);
    }
    receptorIR.resume();
  }
}

#include <SPI.h>
#include <RH_ASK.h>
#define MAX_MSG_LEN 59

RH_ASK fs1000a = RH_ASK( 2000, 11, 12, 10, false);

void setup() {
  Serial.begin(9600);
  if( fs1000a.init()) Serial.print( "Extremo TX. Init OK");
}

void loop() {
 
  // Creamos las variables que vamos a utilizar
  static int i = 0;
  static char msg[MAX_MSG_LEN + 1];
  char mensaje[MAX_MSG_LEN];
  byte len = sizeof(mensaje);

  // Si hay algo en consola para leer lo leemos y lo enviamos
  if( Serial.available()) {
    if( i > MAX_MSG_LEN) {
      Serial.println("Mensaje demasiado largo. Descartando...");
      i = 0;
    }
    else {
      msg[i++] = Serial.read();
    }
   
    // Cambiamos el fin de linea del mensaje, y lo enviamos
    // 10 veces para asegurar que llegue a su destino.
    if( msg[i-1] == '\n'){
      msg[i] = '\0';
      i=0;

      for( int i = 0; i < 10; i++){
        fs1000a.send((uint8_t *)msg, strlen(msg));
        fs1000a.waitPacketSent();
        delay(10);
      }
      Serial.println("Enviado!");
    }
  }

  // Tambien estamos atentos a recibir un mensaje de los SLAVES
  // confirmando la recepcion del mensaje
  if ( fs1000a.recv( (uint8_t*) mensaje, (uint8_t*) &len)){
    delay(200);
    mensaje[len-1] = 0;
    Serial.println(mensaje);
  }

}


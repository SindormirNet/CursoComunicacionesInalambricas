#include <RH_ASK.h>
#include <SPI.h>
#define MAX_MSG_LEN 59
#define LED 2


RH_ASK receptor = RH_ASK(2000, 11, 12, 10, false);


void setup() {
  Serial.begin(9600);
  pinMode( LED, OUTPUT);
  if (receptor.init()) Serial.println("Extremo RX. Init OK");
}



void loop() {
  // Creamos las variables que vamos a utilizar.
  char mensaje_encendido[MAX_MSG_LEN + 1] = "Se ha encendido   ";
  char mensaje_apagado[MAX_MSG_LEN + 1] = "Se ha apagado   ";
  char msg[MAX_MSG_LEN];
  byte len = sizeof(msg);
  char accion[MAX_MSG_LEN];
  char * posicion_accion ;
  char numero_serie[MAX_MSG_LEN];
 
 
  // Leemos si ha habido señal con el receptor.
  if (receptor.recv( (uint8_t*) msg, (uint8_t*) &len)) {
   
    // Con este delay esperamos a que se hayan enviado todas las secuencias para empezar
    // a trabajar con la señal recivida. Asi, podremos enviarla cuando el receptor_master
    // este preparado para recibir.
    delay(80);

    // Aqui cambiamos el ultimo elemento para que sea un fin de cadena
    // esto es indispensable para que la funcion strcmp pueda comparar
    // el mensaje
    msg[len-1]=0;
    Serial.println(msg);

    // Con la funcion strchr buscamos la posicion del primer ' ' para asi poder
    // separar el mensaje en dos partes, la accion, y el codigo clave del receptor
    posicion_accion = strchr(msg, ' ');
    int posicion = posicion_accion - msg;
    if( posicion < 0) posicion = 0;

    // Con este blucle separamos el mensaje msg en los dos codigos, uno en la accion
    // y otro en la clave del receptor
    for( byte i = 0; i < len - posicion; i++){
      if( i >= posicion){
        if( i == posicion){
          numero_serie[i] = 0;
        }
        accion[i - 1] = msg[i + posicion];
      }
      else if( i < posicion){
        numero_serie[i] = msg[i];
      }
    }


    // Primero identificamos si somos el receptor que deseamos, en este caso el numero uno
    if( strcmp( numero_serie, "1") == 0){

      // Gracias a esta funcion podemos comparar dos cadenas de caracteres
      // con lo que apagamos o encendemos el LED.
      if( strcmp( accion, "Encendido") == 0){
        digitalWrite( LED, HIGH);
        delay(50);
       
        // Ademas de encender el LED, enviamos el mensaje para comprobar que el mensaje ha
        // llegado al destinatario.
        for( int i = 0; i < 20; i++){
          receptor.send((uint8_t *)mensaje_encendido, strlen(mensaje_encendido));
          receptor.waitPacketSent();
          delay(10);
        }
        Serial.println("Enviado!");
      }
     
     
      else if( strcmp( accion, "Apagado") == 0){
        digitalWrite( LED, LOW);
        delay(50);
       
        // Ademas de apagar el LED, enviamos el mensaje para comprobar que el mensaje ha
        // llegado al destinatario.
        for( int i = 0; i < 20; i++){
          receptor.send((uint8_t *)mensaje_apagado, strlen(mensaje_apagado));
          receptor.waitPacketSent();
          delay(10);
        }
        Serial.println("Enviado!");
      } 
    }

  }


}

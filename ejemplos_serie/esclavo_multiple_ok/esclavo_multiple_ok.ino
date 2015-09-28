#define ID_ESCLAVO '1'
//#define ID_ESCLAVO '2'
//#define ID_ESCLAVO '3'


void setup()
{
  Serial.begin(19200);
  pinMode(13, OUTPUT);
}

void loop()
{
  char header, comando, destino;

  if (Serial.available()>2){
    header = Serial.read();

    if (header != '_') Serial.read(); //Resincronizamos
    else { //Cabecera valida. Leemos destino y comando
      destino = Serial.read();
      comando = Serial.read();

      if (destino == ID_ESCLAVO){
        if      (comando=='O')  digitalWrite (13, LOW);
        else if (comando=='X')  digitalWrite (13, HIGH); 
      }
    }
  }
}



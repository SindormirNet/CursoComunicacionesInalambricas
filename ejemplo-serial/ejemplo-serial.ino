void setup(){
  Serial.begin(9600); //Indicamos la velocidad del puerto serie 
  pinMode(13, OUTPUT); //Establecemos el pin 13 como salida

  Serial.println("Arduino Arrancando!");
}

void loop() {
  char dato;

  if (Serial.available() > 0) { //¿Ha enviado algún dato el PC?
    dato = Serial.read();       //Guardamos el dato enviado en la variable dato        
    if (dato == 'A'){
      Serial.println("Encendiendo");
      digitalWrite(13, HIGH);
    }
    else if (dato == 'B'){
      Serial.println("Apagando");
      digitalWrite(13, LOW);
    }
  }
}

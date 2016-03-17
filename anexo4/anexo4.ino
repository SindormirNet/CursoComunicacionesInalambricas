#define BASE 0x0013A20000000000

#define ALBERTO        "40ACADFF"
#define ANA            "407B6D2B"
#define FRANCISCO      "409BBF4E"
#define MAITE          "40ACAE7C"
#define JUAN           "409BDF4B"
#define MARIA          "409BBF62"


void setup() {
	Serial.begin(9600);
}

void mePresento (const char* destinatario, const char* nombre){
  Serial.print ("+++");
  delay(1000);
  
  Serial.print ("ATDL ");
  Serial.println (destinatario);
  delay (1000);
  
  Serial.println ("ATCN");
  delay (1000);
  
  Serial.print ("Hola ");
  Serial.print (nombre);
  Serial.println (", soy Jorge");
  delay (1000);
  
}

void loop() {
  mePresento (ALBERTO, "ALBERTO");
  mePresento (ANA, "ANA");
  mePresento (FRANCISCO, "FRANCISCO");
  mePresento (MAITE, "MAITE");
  mePresento (JUAN, "JUAN");
  mePresento (MARIA, "MARIA");

}

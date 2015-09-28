#define TIEMPO 100

void setup(){
  Serial.begin(19200);
}

void loop(){
  Serial.print("_1X");
  delay(TIEMPO);
  Serial.print("_1O");
  delay(TIEMPO);
  Serial.print("_2X");
  delay(TIEMPO);
  Serial.print("_2O");
  delay(TIEMPO);
  Serial.print("_3X");
  delay(TIEMPO);
  Serial.print("_3O");
  delay(TIEMPO);
}

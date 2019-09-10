#include "DHT.h" //Bibliothek einbinden
int richtungA           =12; //Richtung Motor A an Pin 12
int pwmA                =3; //Geschwindigkeit Motor A an Pin 3
int bremseA             =9; //Bremse Motor A an Pin 9
int geschwindigkeit     =255; //Maximalgeschwindigkeit festlegen
int DHTPIN = 2; // Sensor an Pin 2
int DHTTYPE= DHT11; //Sensor ist Typ DHT11
DHT dht(DHTPIN,DHTTYPE); //Sensor wird mit dht angespochen
void setup() {
  Serial.begin(9600); //start serielle Kommunikation
  dht.begin(); // Sensor start
  pinMode(richtungA, OUTPUT); //richtung A als Output definieren
  pinMode(bremseA, OUTPUT); //bremse A als Output definieren
  analogWrite(pwmA, geschwindigkeit); //Wert geschwindigkeit auf Pin 3 schreiben
  digitalWrite(bremseA, HIGH); //Bremse an 
}
void loop() {
  delay(2000); // 2 Sekunden warten
  float Luftfeuchtigkeit=dht.readHumidity(); //Luftfeuchtigkeit lesen und speichern
  float Temperatur=dht.readTemperature(); //Temperatur lesen und speichern
  Serial.print("Luftfeuchtigkeit: "); //Im sereiellen Monitor anzeigen
  Serial.print(Luftfeuchtigkeit);
  Serial.println(" %");
  Serial.print("Temperatur: ");
  Serial.print(Temperatur);
  Serial.print(" Grad Celsius  ");
  if (Temperatur>=20){ //Wenn Temperatur über 25°
    digitalWrite(bremseA, LOW); //Bremse lösen
    digitalWrite(richtungA, HIGH); //Motor vorwärts
  }
  else { //ansonsten
    digitalWrite(bremseA, HIGH); //Bremse an
  }
}

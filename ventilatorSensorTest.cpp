#include "DHT.h" //Bibliothek einbinden
int DHTPIN = 2; //Sensor an Pin 3
int DHTTYPE= DHT11; //Sensortype ist DHT11
DHT dht(DHTPIN,DHTTYPE); //Sensor wird ab jetzt mit dht angesprochen
void setup() {
  Serial.begin(9600); //Serielle Verbindung starten
  dht.begin(); //Sensor starten
  }
void loop() {
  delay(2000); //2 Sekunden warten
  float Luftfeuchtigkeit=dht.readHumidity(); //Luftfeuchtigkeit auslesen,
                                             // unter "Luftfeuchtigkeit"       					       //speichern
  float Temperatur=dht.readTemperature(); // Temperatur auslesen und
                                          //unter "Temperatur" speichern 
  Serial.print("Luftfeuchtigkeit: "); //Text im seriellen Monitor anzeigen
  Serial.print(Luftfeuchtigkeit);
  Serial.println(" %");
  Serial.print("Temperatur: ");
  Serial.print(Temperatur);
  Serial.print(" Grad Celsius  ")
}

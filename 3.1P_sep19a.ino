#include "arduino_secrets.h"
// DHT sensor library - Version: Latest 
#include <DHT.h>
#include <DHT_U.h>

#include "thingProperties.h"

#include <DHT.h>

#define DHTPIN  13   
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);
float temperature;
float humidity;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  pinMode(LED_BUILTIN, OUTPUT);
  dht.begin();
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  delay(1000);
  
 
  
  Serial.print("Temperature: ");
  Serial.print("°C");
  Serial.print(" Humidity: ");
  Serial.print("%");
  Serial.println();
  delay(1000);
}

void onLedChange()  {
  // Add your code here 
  if (led == 1)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }

}

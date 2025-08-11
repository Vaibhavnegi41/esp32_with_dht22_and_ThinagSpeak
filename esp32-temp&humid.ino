// Channel ID: 3032392
// channel api key :3ZDK9IM7LI4GT81L

#include "WiFi.h"
#include "HTTPClient.h"
#include "DHT.h"

// ---------- WiFi Credentials ----------
const char* ssid = "StayHappy1234";   
const char* password = "Vaibhav6208";

// ---------- ThingSpeak API ----------
String apiKey = "3ZDK9IM7LI4GT81L"; 
const char* server = "http://api.thingspeak.com/update";

// ---------- DHT Sensor Setup ----------
#define DHTPIN 15      
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// ---------- LED Setup ----------
#define LED_PIN 2    
float tempThreshold = 30.0; 

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  dht.begin();

 
  Serial.print("Connecting to WiFi");
  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Connected!");
}

void loop() {
  // Read sensor data
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C | Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  // LED control
  if (temperature > tempThreshold) {
    digitalWrite(LED_PIN, HIGH); // LED ON
  } else {
    digitalWrite(LED_PIN, LOW);  // LED OFF
  }

  // Send data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = String(server) + "?api_key=" + apiKey +
                 "&field1=" + String(temperature) +
                 "&field2=" + String(humidity);

    http.begin(url);
    int httpCode = http.GET();

    if (httpCode > 0) {
      Serial.println("Data sent to ThingSpeak");
    } else {
      Serial.println("Error sending data");
    }
    http.end();
  }

  delay(20000); 
}

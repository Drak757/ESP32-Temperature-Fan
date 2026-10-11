#include <DHT.h> //loading Dht library for reading humidity / temperature sensor

const int dhtPin = 27; //variable creation for DHt ... connected to the GPIO 27 pin

#define DHTTYPE DHT11 //defining which sensor is being used specifically the DHT11

DHT dht(dhtPin, DHTTYPE); //creation of the dht sensor object to use later...

void setup() //famous void setup that runs once when the esp32 starts
{
  Serial.begin(115200); //setting.communication.speed both the serial monitor & esp32 have to be on the same speed to prevent collection of garbage
  dht.begin(); //start sensor
}

void loop()
{
  float temperatureC = dht.readTemperature();
  float humidity = dht.readHumidity();

  if(isnan(temperatureC) || isnan(humidity))
  {
    Serial.println("Failed to read DHT11!");
    delay(2000);
    return;
  }

  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  Serial.print("Temperature: ");
  Serial.print(temperatureF);
  Serial.print(" F | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000);
}





#include <Wire.h>
#include "DHT.h"

// Definiciones de hardware
#define LIDAR_ADDRESS 0x62 // Dirección del sensor LIDAR
#define DHTPIN 2 // Pin donde se conecta el sensor de temperatura
#define DHTTYPE DHT11 // Tipo de sensor de temperatura

// Inicialización de objetos
Lidar lidar(LIDAR_ADDRESS);
TemperatureSensor tempSensor(DHTPIN);

void setup() {
    Serial.begin(9600); // Inicializa la comunicación serial
    lidar.init(); // Inicializa el LIDAR
    tempSensor.init(); // Inicializa el sensor de temperatura
}

void loop() {
    // Leer distancia del LIDAR
    float distance = lidar.readDistance();
    if (distance >= 0) {
        Serial.print("Distancia: ");
        Serial.print(distance);
        Serial.println(" m");
    } else {
        Serial.println("Error al leer el LIDAR");
    }

    // Leer temperatura y humedad
    float temperature = tempSensor.readTemperature();
    float humidity = tempSensor.readHumidity();
    
    if (!isnan(temperature) && !isnan(humidity)) {
        Serial.print("Temperatura: ");
        Serial.print(temperature);
        Serial.print(" °C, Humedad: ");
        Serial.print(humidity);
        Serial.println(" %");
    } else {
        Serial.println("Error al leer el sensor de temperatura");
    }

    delay(2000); // Esperar 2 segundos antes de la próxima lectura
}

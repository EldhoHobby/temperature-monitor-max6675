#include "max6675.h"

// Define the Arduino pins, the MAX6675 module is connected to
int SO_PIN = 4;  // Serial Out (SO) pin
int CS_PIN = 5;  // Chip Select (CS) pin
int SCK_PIN = 6; // Clock (SCK) pin

// Create an instance of the MAX6675 class with the specified pins
MAX6675 thermocouple(SCK_PIN, CS_PIN, SO_PIN);

void setup() {
  Serial.begin(9600); // Set baud rate to 9600
  delay(500);         // Wait for the Serial connection to initialize
}

void loop() {
  // Read the temperature in Celsius
  float temperatureC = thermocouple.readCelsius();

  // Read the temperature in Fahrenheit
  float temperatureF = thermocouple.readFahrenheit();

  // Output Celsius data for the Serial Plotter (every second)
  Serial.print("Celsius\t");
  Serial.println(temperatureC); // Only print Celsius to the Serial Plotter

  // Output both Celsius and Fahrenheit to the Serial Monitor (every second)
  Serial.print("Temperature (Celsius): ");
  Serial.print(temperatureC);
  Serial.print("\xC2\xB0"); // Degree symbol
  Serial.print("C  |  ");
  Serial.print("Temperature (Fahrenheit): ");
  Serial.print(temperatureF);
  Serial.print("\xC2\xB0"); // Degree symbol
  Serial.println("F");

  delay(1000); // Wait 1 second before taking another reading
}

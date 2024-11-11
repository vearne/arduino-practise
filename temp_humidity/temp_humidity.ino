#include <DHT11.h>
#include <Bonezegei_LCD1602_I2C.h>

DHT11 dht11(2);
Bonezegei_LCD1602_I2C lcd(0x27);

void setup() {
  // Initialize serial communication to allow debugging and data readout.
  // Using a baud rate of 9600 bps.
  Serial.begin(9600);

  lcd.begin();
}

void loop() {
  int temperature = 0;
  int humidity = 0;

  // Attempt to read the temperature and humidity values from the DHT11 sensor.
  int result = dht11.readTemperatureHumidity(temperature, humidity);

  // Check the results of the readings.
  // If the reading is successful, print the temperature and humidity values.
  // If there are errors, print the appropriate error messages.
  if (result == 0) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C\tHumidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    String str = String("Temperat: ") + temperature + String(" C");
    lcd.setPosition(0, 0);
    lcd.print(str.c_str());

    lcd.setPosition(0, 1);
    str = str = String("Humidity: ") + humidity + String(" %");
    lcd.print(str.c_str());
  } else {
    // Print error message based on the error code.
    Serial.println(DHT11::getErrorString(result));
  }

  delay(10000);
}

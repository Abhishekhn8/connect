#include <dht11.h>

dht11 DHT11;

#define DHT11_PIN 4

const int TEMP_ID = 100;
const int HUM_ID  = 200;

void setup() {
  Serial.begin(9600);
}
void loop() {
  int chk = DHT11.read(DHT11_PIN);
  byte humVal = trunc(DHT11.humidity);
  int16_t tempVal = trunc(DHT11.temperature);

  Serial.write(TEMP_ID);
  Serial.write(highByte(tempVal));
  Serial.write(lowByte(tempVal));
  Serial.write(HUM_ID);
  Serial.write(humVal);

  delay(2000);
}

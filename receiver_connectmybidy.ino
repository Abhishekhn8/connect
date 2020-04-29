const int BUF_LEN = 5;

byte buffer[BUF_LEN];
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() == 5) {
    for (int i = 0; i < BUF_LEN; i++) {
      buffer[i] = Serial.read(); 
    }
  byte tempHigh = buffer[1];
  byte tempLow = buffer[2];
  int16_t temp16 = (tempHigh << 8) + tempLow;
  Serial.print("Temperature ID: ");
  Serial.print(buffer[0]);
  Serial.print('\t');
  Serial.print("Temperature: ");
  Serial.print(temp16);
  Serial.print('\t');
  Serial.print("Humidity ID: ");
  Serial.print(buffer[3]);
  Serial.print('\t');
  Serial.print("Humidity: "); 
  Serial.print(buffer[4]);
  Serial.println();
  }
}

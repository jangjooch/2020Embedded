int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  // 이러한 과정 없이 진행하면 Fade처럼 되지 않는다.
  while (millis() < 5000) {
    sensorValue = analogRead(0);
    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }
    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(0);
  int dacValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
  dacValue = constrain(dacValue, 0, 255);
  digitalWrite(3, dacValue);
  Serial.println(dacValue);
}

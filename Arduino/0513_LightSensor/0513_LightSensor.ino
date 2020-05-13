
// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to
const int ledPin = 3;        // pin that the LED is attached to

// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

void setup() {
  // turn on LED to signal the start of the calibration period:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // calibrate during the first five seconds
  
  while (millis() < 5000) {
    // 첫 5초동안 clibration 값 제한을 위하여
    // 최댓값과 최솟값을 설정하는 과정이다.
    // 이러한 과정이 있는 이유는 어떠한 값이 입력 될지
    // 모르는 상황속에서 즉 입력값이 0~1023을 벗어나는
    // 값을 받는경우가 있을 수 있기때문에 이러한 설정과정을
    // 통하여 정상적으로 0 ~ 255로 바꿀 수 있는 map을 수행한다.
    // 이후 극단적으로 치우쳐져있는 과정을 배제하기 위하여
    // 설정되어 있는 것이다.
    sensorValue = analogRead(sensorPin);
    
    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  // signal the end of the calibration period
  digitalWrite(13, LOW);
}

void loop() {
  // read the sensor:
  sensorValue = analogRead(sensorPin);

  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);

  // fade the LED using the calibrated value:
  analogWrite(ledPin, sensorValue);
}

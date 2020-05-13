

const int buttonPin = 2;    
const int ledPin = 3;      

// Variables will change:
int ledState = HIGH;         
int buttonState;             
int lastButtonState = LOW;   

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    // 현재 상태가 바뀌었을 경우
    lastDebounceTime = millis();
    // 현재 시간을 기록한다
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // 이후현재 시간과 방금 시간의 차가 50ms 보다 클경우 진행토록 한다.
    // 즉 50ms이하의 바운스 현상을 방지하기 위함이다.
    // 이는 곧 순간적인 바운스 현상을 걸러내기 위함이다.
    if (reading != buttonState) {
      buttonState = reading;    
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }
  digitalWrite(ledPin, ledState);
  // 입력에 따라 Low High를 설정한다.
  lastButtonState = reading;
  // 현재 상태를 기록한다.
}

unsigned char num;

int state;
int showidx = -1;
int saveidx = -1;

unsigned long startMillis;

int nums[] = {0, 0, 0, 0, 0};
int arrLength = 5;
int numdir = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  DDRD |= 0xF0;
  DDRB |= 0x0F;

  SREG |= 0x80;
  EIMSK = 0x03;
  EICRA = 0x05;

  num = 0x01;
  state = 0;
  showidx = -1;
  saveidx = -1;
}

unsigned long int0Milli = 0;
unsigned long int1Milli = 0;
// ISR INT0의 서브루틴 생성
ISR(INT0_vect){
  if(int0Milli == 0){
    int0Milli = millis();
  }
  else{
    if(millis() - int0Milli > 50){
      Serial.print("save ");
      Serial.println(num);
      
      state = 1;
      saveidx ++;      
      if(saveidx == arrLength){
        for(int i = 0 ; i < 4 ; i++){
          nums[i] = nums[i+1];
        }
        saveidx = 4;
      }
      nums[saveidx] = num;
      int0Milli = 0;
    }
    int0Milli = 0;
  }
}

ISR(INT1_vect){
  if(int1Milli == 0){
    int1Milli = millis();
  }
  else{
    if(millis() - int1Milli > 50){
      Serial.print(nums[0]);Serial.print(" ");
      Serial.print(nums[1]);Serial.print(" ");
      Serial.print(nums[2]);Serial.print(" ");
      Serial.print(nums[3]);Serial.print(" ");
      Serial.println(nums[4]);
      showidx ++;
      if(showidx == arrLength){
        showidx = 0;
      }      
      Serial.print("show ");
      Serial.println(showidx);
      state = 2;      
      int1Milli = 0;
    }
  }  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(startMillis == 0){
    startMillis = millis();
  }
  // 불조절
  else{
    if(millis() - startMillis > 200){
      PORTD = ~((num & 0x0F)<<4);
      PORTB = ~(num >> 4);
      // 불 와리가리
      if(state == 0){        
        if(numdir == 0){          
          if(num & 0x80){
            numdir = 1;
          }
          else{
            num = num << 1;
          }
        }
        else if(numdir == 1){
          if(num &0x01){
            numdir = 0;
          }
          else{
            num = num >> 1;
          }
        }
      }
      // 불 기록
      else if(state == 1){  
        Serial.print(saveidx);Serial.print(" ");
        Serial.println(num);
        
        PORTD = ~((num & 0x0F)<<4);
        PORTB = ~(num >> 4);
        
        unsigned long forDelay = millis();
        while(millis() - forDelay < 1000){
          
        }
        state = 0;
      }
      // 기록불 켜기
      else if(state == 2){
        num = nums[showidx];
        PORTD = ~((num & 0x0F)<<4);
        PORTB = ~(num >> 4);
      }
      startMillis = 0;
    }
  }
}

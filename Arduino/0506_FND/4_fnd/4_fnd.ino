int i, j;
int segment[10][8]={
    {1, 1, 1, 1, 1, 1, 0, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1, 0}, // 2
    {1, 1, 1, 1, 0, 0, 1, 0}, // 3
    {0, 1, 1, 0, 0, 1, 1, 0}, // 4
    {1, 0, 1, 1, 0, 1, 1, 0}, // 5
    {1, 0, 1, 1, 1, 1, 1, 0}, // 6
    {1, 1, 1, 0, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1, 0}, // 8
    {1, 1, 1, 1, 0, 1, 1, 0}, // 9
  };
void setup()
{
  pinMode(2, OUTPUT);// A
  pinMode(3, OUTPUT);// B
  pinMode(4, OUTPUT);// C
  pinMode(5, OUTPUT);// D
  pinMode(6, OUTPUT);// E
  pinMode(7, OUTPUT);// F
  pinMode(8, OUTPUT);// G
  pinMode(9, OUTPUT);// DP
  /*
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(6, LOW);
  */
  
}

void loop()
{
  
  for( j = 0 ; j < 10 ; j++){
      for( i = 0 ; i < 8 ; i++){
        if(segment[j][i]){
          digitalWrite(i+2, LOW);
          // 연결부위가 DWM 2 부터 연결하였으니 +2 를 하여 해당
          // 자리에 입력을 상정하도록 한다.
        }
        else{
          digitalWrite(i+2, HIGH);
        }
    }
    delay(1000);
  }
  
}

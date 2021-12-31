// Do not remove the include below

#define LED1 6
#define LED2 7
#define LED3 8
#define LED4 9
#define LED5 10
#define LED6 11
#define LED7 12
#define LED8 13

int len = 0, i = 0, j = 0;
int Feedback = 0, output = 0;


//The setup function is called once at startup of the sketch
void setup() {
// Add your initialization code here
  Serial.begin(9600);
 
}

//-----------------------------------------------------------------------
void LFSR_127bit() {
  // 초기화
  len = 127;
  String binary="";
  int lfsr[127]; // LFSR값을 저장할 비트
  for(int i=0; i<len-1; i++){
    lfsr[i]=random(0, 1);}
  lfsr[127]=1;  
  
  int bTemp[127];
  for (i = 0; i < len; ++i) {
    bTemp[i] = lfsr[i];
  }

  // 처음숫자와 같은때까지 반복
  for (int count = 1; true; ++count) {
    
    //prime numbers 소수 골라내기
    binary="";
    for(int b=2; b<73;b++){
      int counter=0;
      for(int c=1;c<=b;c++){
        if(b%c==0) counter+=1;
      }
      if(counter==2){
       binary+=(String)bTemp[b-1]; 
      }
    }
    double decimal = 0;
    String bits="";
    int p = 0;
    int index=19;
    while(true){
      if(index == -2){
        break;
      } else {
        bits = binary[index];
          int temp = bits.toInt();
          decimal += (temp * pow(2, p));
          
          p++;
          index--;
       }
    }
    String Dec= String(decimal*100);
    
    // Shift 연산
    Feedback = (bTemp[126] + bTemp[53] + bTemp[7]+ bTemp[6] + bTemp[5]+ bTemp[4]+ bTemp[3]+ bTemp[2]+ bTemp[1]+ bTemp[0] + 1) % 2;
    output = bTemp[126];
    for (i = len - 1; i > 0; --i) {
      bTemp[i] = bTemp[i - 1];
    }

   int a = (Dec.toInt()/10000);    // 랜덤생성한 OTP와 입력받은 네 자리 수 비교
   if (a < 1000 || a>=10000){      //#2
    Serial.available();                 //#3
    int b = random(1000,9999);              //#4
    Serial.print("your new OTP!:");
    Serial.print(b);
    Serial.println();
    Serial.print("put otp in 5sec :");
    delay(5000);
    int input = Serial.parseInt();               //#5
   
    
    if(input == b){                   
      Serial.print("currect");
      }
      else{Serial.print("fail");}
    
    }else{
      Serial.print("your new OTP!:");
      Serial.print(a);
      Serial.println();
        Serial.print("put otp in 5sec :");
        delay(5000);
    int input1 = Serial.parseInt();
    if(input1 == a){
      Serial.print("currect");
      }
      else{Serial.print("fail");}
    }
    Serial.println();
   

   
    
 

    // add Feedback
    bTemp[0] = Feedback;
   
    // 검사
    for (i = 0; i < len; ++i) {
      if (bTemp[i] != lfsr[i]) {
        break;
      }
    }
    if (i == len) {
      Serial.print("Original LFSR :  | ");
      for (i = 0; i < len; ++i) {
        Serial.print(lfsr[i]);
        Serial.print(" | ");
      }
      Serial.print("\t LFSR Value is SAME!!!\n\tTotal");
      Serial.print(count);
      Serial.print(" runs");
      Serial.println();
      
      break;
    } else {
       delay(5000);
    }
  }
  delay(5000);
}
//-----------------------------------------------------------------------

//=======================================================================
// The loop function is called in an endless loop
void loop() {
//Add your repeated code here
    LFSR_127bit();
//      LFSR_8bit();
//      LFSR_7bit();
//      LFSR_6bit();
//      LFSR_5bit();
//      LFSR_4bit();
//      LFSR_3bit();
//      LFSR_2bit();
}

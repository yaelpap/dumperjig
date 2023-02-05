
int dir1=A0;
int dir2=A1;
int PWM=A2;
int mspeed=255;
int SEL1=A4;
int push1=2;
int push2=3;
int val1;
int val2;
int led=12;
int direction=0;
int isFirstTime = 1;

void setup() {
pinMode (led, OUTPUT);
pinMode (dir1, OUTPUT);
pinMode (dir2, OUTPUT);
pinMode (PWM, OUTPUT);
pinMode (push1, INPUT_PULLUP);
pinMode (push2, INPUT_PULLUP);
digitalWrite (SEL1, HIGH);
analogWrite (PWM, mspeed);
}

void loop() {
 val1= digitalRead (push1);
 val2= digitalRead (push2);
if (val1==0) {
  if (isFirstTime !=1){
    delay (3000);
  }
  direction = 1;
  }
isFirstTime = 0;

if (direction==0){
digitalWrite (dir1, LOW);
digitalWrite (dir2, HIGH);
}
else {
  digitalWrite (dir1, HIGH);
  digitalWrite (dir2, LOW);
}
 if(val2==LOW){
  digitalWrite (dir1, LOW);
  digitalWrite (dir2, LOW);
  digitalWrite (led, HIGH); 
  exit(0);
 }
}
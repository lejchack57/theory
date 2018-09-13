#include <SoftwareSerial.h> 
int en1 = 6, en2 = 3;
int in1 = 8, in2 = 7, in3 = 4, in4 = 5; 
SoftwareSerial BTSerial(13, 12); // RX, TX on arduino
char s;
int speedBot = 180;
void setup() {
  pinMode(en1, OUTPUT); pinMode(en2, OUTPUT);
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  BTSerial.begin(9600);
}

void loop() {
  if (BTSerial.available()){
    s = (char)BTSerial.read();
  }
  //speed
  if(s == '0'){ speedBot = 0;}
  else if (s == '1'){ speedBot = 120;}
  else if (s == '2'){ speedBot = 135;}
  else if (s == '3'){ speedBot = 150;}
  else if (s == '4'){ speedBot = 165;}
  else if (s == '5'){ speedBot = 180;}
  else if (s == '6'){ speedBot = 195;}
  else if (s == '7'){ speedBot = 210;}
  else if (s == '8'){ speedBot = 225;}
  else if (s == '9'){ speedBot = 240;}
  else if (s == 'q'){ speedBot = 255;}

  //speedBot = map(speedBot, 0, 10, 100, 255);

  //direction
  if (s == 'F'){
    forward(); 
  }else if (s == 'B'){
    backward(); 
  } else if (s == 'L'){
    left(); 
  }else if (s == 'R'){
    right(); 
  }else if (s == 'I'){
    forwardRight(); 
  }else{
    analogWrite(en1, 0);
    analogWrite(en2, 0);
  }
}

void forward(){
  analogWrite(en1, speedBot);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  analogWrite(en2, speedBot);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void backward(){
  analogWrite(en1, speedBot);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);

  analogWrite(en2, speedBot);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void left(){
  analogWrite(en1, speedBot);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  analogWrite(en2, speedBot);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void right(){
  analogWrite(en1, speedBot);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);

  analogWrite(en2, speedBot);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void forwardRight(){
  analogWrite(en1, speedBot);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  analogWrite(en2, speedBot-25);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

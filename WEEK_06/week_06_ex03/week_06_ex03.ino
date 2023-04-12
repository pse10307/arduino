int num = 0;
byte numbers[10]= {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xF6};
void displayNumber(int n){
int pin = 2;
for(int i = 0; i < 8; i++) {
boolean state = bitRead(numbers[n], 7-i);
digitalWrite(pin+i, state);
}
}
void setup() {
pinMode(12, INPUT);   // 숫자 증가를 위한 푸시버튼 연결
pinMode(13, INPUT);   // 숫자 감소를 위한 푸시버튼 연결
for (int i = 2; i <= 9; i++) {
pinMode(i, OUTPUT);
}
digitalWrite(9, HIGH);
}

void loop() {
if (digitalRead(12) == HIGH){
++num;
if (num > 9) { 
num = 0;
}
}
if (digitalRead(13) == HIGH){
--num;
if (num < 0) {
num = 9;
}
}
displayNumber(num);
delay(300);
}


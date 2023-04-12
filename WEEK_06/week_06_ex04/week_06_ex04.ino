byte Numbers[10]= {0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110, 0b10110110, 0b10111110, 0b11100100, 0b11111110, 0b11110110};
int segPins[7] = {2,3,4,5,6,7,8};
int digNum = 2;
int digPin[] = {12, 13};
void displayDigit(int x, int d) {
int value = Numbers[x];
boolean segSet = LOW;
digitalWrite(digPin[0], LOW);
digitalWrite(digPin[1], LOW); 
for (int led=0; led<7; led++) {
if (value & 0x02) segSet = HIGH;
else segSet = LOW;
digitalWrite(10-segPins[led], segSet);
value >>= 1;
}
digitalWrite(digPin[d], HIGH);
}

void displayNumber(int n) {
if (n==0) displayDigit(0, 0);
else {
for (int i=0; i<digNum; i++) {
if (n > 0) {
displayDigit(n % 10, i);
n = n / 10; 
}
delay(10); 
}
}
}

void setup() {
for(int i=0;i<7; i++)
pinMode(segPins[i], OUTPUT);
for(int j=0; j<digNum; j++)
pinMode(digPin[j], OUTPUT); 
}

void loop() {
for(int i=0; i<1000; i++) {
displayNumber(i/10);
}
}

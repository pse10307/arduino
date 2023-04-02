// TMP36 온도 측정
int Pin = A0;   // 입력 핀
int reading; 
float tempC;
float V;
void setup() {
  Serial.begin(9600);   // 시리얼 통신 속도 설정
}
void loop() {
  reading = analogRead(Pin);   // 센서 값 읽어옴
  V=reading*5.0/1023;
  tempC=(V-0.5)*100;
  Serial.print(tempC);   // 센서 값 섭씨온도로 변환(TMP36 계산 공식에 의함)
  Serial.println(" 도");
  delay(1000);   // 온도 측정 간격 설정 (1000 = 1초)
}

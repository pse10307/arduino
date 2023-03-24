void setup() {
  Serial.begin(9600); // 시리얼 모니터 속도를 9600으로
  pinMode(4, OUTPUT);
}
void loop() {
  int sensorValue = analogRead(A0); // 아날로그 값 읽기
  Serial.println(sensorValue); // 시리얼 포트로 출력
  if (sensorValue > 500) digitalWrite(4, LOW);
  else digitalWrite(4, HIGH);
  //delay(200); // 0.2초 동안 기다림
}

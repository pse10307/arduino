// 출력핀(trig)과 입력핀(echo) 연결 설정, 다른 핀을 연결해도 됨
int trigPin = 2; int echoPin = 3;
// 시리얼 속도 설정, trigPin을 출력, echoPin을 입력으로 설정
void setup() {
Serial.begin(9600);
  pinMode(trigPin, OUTPUT);  // 출력 핀으로 설정
  pinMode(echoPin, INPUT);  // 신호를 받는 핀 입력 설정
}
void loop() {
  float duration, distance;
  digitalWrite(trigPin, HIGH);   delay(10);
  digitalWrite(trigPin, LOW);
  // echoPin이 HIGH를 유지한 시간을 저장
  duration = pulseIn(echoPin, HIGH);
  // HIGH일 때 초음파가 보냈다가 돌아오는 시간을 가지고 거리를 계산
  // 340은 초당 소리의 속도이고 10000은 밀리세컨드를 세컨드로, 왕복거리이므로 2로 나눔
  distance = ((float)(340 * duration) / 10000) / 2;
  // 시리얼모니터에 Echo가 HIGH인 시간 및 거리를 표시
  Serial.print("Duration:");     Serial.print(duration);
  Serial.print("\nDistance:");  Serial.print(distance);
  Serial.println("cm\n");       delay(500);
}

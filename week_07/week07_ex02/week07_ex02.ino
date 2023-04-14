#include <Servo.h>
Servo myServo; // 서보모터 객체를 생성하고 이름을 myServo로 설정
int motorPin = 12; // 서보모터를 12번 핀에 연결
int pushPin = 7; // 푸시 버튼을 7번 핀에 연결
int angle = 90; // 초기에 샤프트는 중간에 위치
int state=0; // 회전방향 설정 (state 값 0 :  시계 방향 / 1 : 반시계 방향)
void setup() {
myServo.attach(motorPin); // 서보 모터를 아두이노의 해당 핀에 연결
pinMode(pushPin, INPUT); // 푸시 버튼이 연결된 핀을 입력 모드로 설정
Serial.begin(9600); // 시리얼 모니터와 통신 
Serial.println("Enter the push button."); // 시리얼 모니터에 문자열 출력
}

void loop() {
if (digitalRead(pushPin) == HIGH){
if (state == 0) { 
angle += 1; // 각도를 1도씩 증가
if (angle>=180) state = 1; // 회전 방향을 반시계 방향으로 전환
myServo.write(angle); // angle 값을 서보에게 전달하여 기록
delay(10);
Serial.println(angle); // 현재 각도를 시리얼 모니터에 표시
}
else { 
angle -= 1;
if (angle<=0) state = 0; // 회전 방향을 시계 방향으로 전환
myServo.write(angle);
delay(10);
Serial.println(angle); 
}
}
}

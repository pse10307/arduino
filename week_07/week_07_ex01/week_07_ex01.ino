#include <Servo.h>
Servo myServo; // 서보모터를 제어하기 위한 서보 객체의 생성
// 대부분의 보드에서 서보 객체를 12개까지 생성할 수 있음
int angle = 90; // 서보 위치(각도)를 저장하기 위한 변수
void setup() {
myServo.attach(12); // 핀 12번에 연결된 서보를 서보 객체에 배속시킴
}
void loop() {
for (angle = 0; angle <= 180; angle += 1) { // 0도에서 180도로 1도씩 이동
myServo.write(angle); // pos가 가진 각도의 위치로 이동
delay(15); // 서보가 해당 위치에 도달할 때까지 15ms 대기
}
for (angle = 180; angle >= 0; angle -= 1) { // 180도에서 0도로 1도씩 이동
myServo.write(angle); // pos가 가진 각도의 위치로 이동
delay(15); // 서보가 해당 위치에 도달할 때까지 15ms 대기
} 
}

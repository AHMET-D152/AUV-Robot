#include <Servo.h>

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
Servo motor5;
Servo motor6;

// Ayarlar
int min_pwm = 1500;
int max_pwm = 1700;
int adim = 25;              // PWM artış/azalış adımı
int bekleme = 500;          // Her adım arasında bekleme süresi (ms)

void setup() {
  Serial.begin(115200);

  // Motor pinlerini bağla
  motor1.attach(3);
  motor2.attach(5);
  motor3.attach(6);
  motor4.attach(9);
  motor5.attach(10);
  motor6.attach(11);

  Serial.println("Motor testi");

  test_motor(motor1, "Motor 1");
  test_motor(motor2, "Motor 2");
  test_motor(motor3, "Motor 3");
  test_motor(motor4, "Motor 4");
  test_motor(motor5, "Motor 5");
  test_motor(motor6, "Motor 6");

  Serial.println("Tüm motorlar testten geçti.");
}

void loop() {
  // Boş. Setup'ta test bitince duracak.
}

void test_motor(Servo &motor, const char* isim) {
  Serial.print("⚙️ ");
  Serial.print(isim);
  Serial.println(" test ediliyor...");
    delay(500);
  // Yavaş yavaş artır
  for (int pwm = min_pwm; pwm <= max_pwm; pwm += adim) {
    motor.writeMicroseconds(pwm);
    delay(bekleme);
  }

  delay(500); // Tepe hızda kısa bekleme

  // Yavaş yavaş azalt
  for (int pwm = max_pwm; pwm >= min_pwm; pwm -= adim) {
    motor.writeMicroseconds(pwm);
    delay(bekleme);
  }

  delay(1000);
  motor.writeMicroseconds(1500); 
}

#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

String comando = "";

void setup() {
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);

  Serial.begin(9600); // Comunicação com o App Inventor
}

void loop() {
  if (Serial.available()) {
    comando = Serial.readStringUntil('\n');

    if (comando == "torneira1") {
      ativarTorneira(servo1);
    } else if (comando == "torneira2") {
      ativarTorneira(servo2);
    } else if (comando == "torneira3") {
      ativarTorneira(servo3);
    }
  }
}

void ativarTorneira(Servo s) {
  s.write(120);           // Gira 120 graus (ajuste se necessário)
  delay(3000);            // Espera 3 segundos com a "torneira" aberta
  s.write(0);             // Volta à posição original
}

#include <BluetoothSerial.h>
#include <Servo.h>

BluetoothSerial SerialBT;

Servo servo1;
Servo servo2;
Servo servo3;

int pos1 = 90;  // posição inicial do servo1
int pos2 = 90;  // posição inicial do servo2
int pos3 = 90;  // posição inicial do servo3

String comando = "";

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Torneiras"); // Nome visível via Bluetooth

  servo1.attach(2);  // Agora nos pinos 2, 3 e 4
  servo2.attach(3);
  servo3.attach(4);

  // Mover os servos para posição inicial
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
}

void loop() {
  if (SerialBT.available()) {
    comando = SerialBT.readStringUntil('\n');
    comando.trim(); // Remove espaços extras

    if (comando == "torneira1") {
      ativarTorneira(servo1, pos1);
    } else if (comando == "torneira2") {
      ativarTorneira(servo2, pos2);
    } else if (comando == "torneira3") {
      ativarTorneira(servo3, pos3);
    }
  }
}

void ativarTorneira(Servo& s, int posAtual) {
  int novaPos = posAtual + 120;
  if (novaPos > 180) novaPos = 180; // Limita o ângulo máximo

  s.write(novaPos);   // Abre a torneira (gira)
  delay(3000);        // Aguarda 3 segundos
  s.write(posAtual);  // Fecha a torneira (volta)
}

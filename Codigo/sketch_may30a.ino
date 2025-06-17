#include"Servo.h"
Servo meuservo;         
Servo meuservo1;     
Servo meuservo2;     
int angulo = 0;            
void setup() {
  meuservo.attach(2);
  meuservo1.attach(3);
  meuservo2.attach(4);
}
 
void loop() {
  for (angulo = 110; angulo < 180; angulo += 10) {     
    meuservo.write(angulo);    
    meuservo1.write(angulo);   
    meuservo2.write(angulo);                          
    delay(2000);                                       
  }
 
  meuservo.write(90);                                  
  delay(2000);                                         // Aguarda 2 segundos para continuar
 
  for (angulo = 70; angulo >= 0; angulo -= 10) {       // Executa movimentos no sentido anti horário
    meuservo.write(angulo); 
    meuservo1.write(angulo);   
    meuservo2.write(angulo);                              // Executa o ângulo de 10 em 10 graus
    delay(2000);                                       // Cada velocidade funciona por 2 segundos
  }
 
  meuservo.write(90); 
  meuservo1.write(90);   
  meuservo2.write(90);                                    // Para o servo motor
  delay(2000);                                         // Aguarda 2 segundos para continuar
}
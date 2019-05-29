// incluir a biblioteca Servo.h
#include <Servo.h>

// criar a referência ao servo
Servo meuServo;  

// definir o pino analógico para o ptenciômetro
int const pinoPotenciometro = A0; 
// variável para guardar o valor lido do potenciômetro
int valorPotenciometro;  
// váriavel para mapear o valor analógico para o ângulo do servo
int angulo;

void setup() {
  // definir o pino (9) em que o servo receberá o comando
  meuServo.attach(9);
  // iniciar a monitor serial para visualizar os valores das variáveis
  Serial.begin(9600);
}

void loop() {
  // ler o valor do potenciômetro
  valorPotenciometro = analogRead(pinoPotenciometro);
  // exibir no monitor serial o valor lido
  Serial.print("Valor potenciômetro: ");
  Serial.print(valorPotenciometro);

  // mapear o valor analógico lido (0-1024) para ângulo (0-179)
  angulo = map(valorPotenciometro, 0, 1023, 0, 179);

  // exibir no monitor serial o ângulo
  Serial.print(", ângulo: ");
  Serial.println(angulo);

  // definir a ângulo em que o servo deve estar
  meuServo.write(angulo);

  // esperar 15 milisegundos para a próxima leitura
  delay(15);
}

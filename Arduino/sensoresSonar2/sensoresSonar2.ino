int limiteDistancia = 0;
int cm = 0;

long leDistanciaUltrassonica(int pinoTrigger, int pinoEcho)
{
  // limpar o trigger
  pinMode(pinoTrigger, OUTPUT);
  digitalWrite(pinoTrigger, LOW);
  delayMicroseconds(2);
  // definir como ligado o trigger por 10 microsegundos
  digitalWrite(pinoTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrigger, LOW);
  pinMode(pinoEcho, INPUT);
  // ler o pulso enviado
  return pulseIn(pinoEcho, HIGH);
}

void setup()
{
  // iniciar o monitor serial para ver as distâncias medidas
  Serial.begin(9600);

  // definir os pinos dos LEDs
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  // definir limite de distância para ativar cada LED
  limiteDistancia = 350;
  // medir a distância do ping
  cm = 0.01723 * leDistanciaUltrassonica(7, 6);

  Serial.print(cm);
  Serial.println("cm");

  // dependendo do limite aceitável, acender mais ou menos LEDs
  if (cm > limiteDistancia) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (cm <= limiteDistancia && cm > limiteDistancia - 100) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (cm <= limiteDistancia - 100 && cm > limiteDistancia - 250) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  if (cm <= limiteDistancia - 250 && cm > limiteDistancia - 350) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  if (cm <= limiteDistancia - 350) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  // esperar 100 milisegundos
  delay(100);
}

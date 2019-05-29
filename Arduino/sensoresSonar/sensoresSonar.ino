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
}

void loop()
{
  // medir a distância do ping
  cm = 0.01723 * leDistanciaUltrassonica(7, 6);

  Serial.print(cm);
  Serial.println("cm");

  // esperar 100 milisegundos
  delay(100);
}

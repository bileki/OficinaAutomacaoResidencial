void setup()
{
  // definir o pino do LED
  pinMode(13, OUTPUT);
}

void loop()
{
  // dar o comando de ligar
  digitalWrite(13, HIGH);
  // esperar 1000 milisegundos (1s)
  delay(1000);
  // dar o comando de desligar
  digitalWrite(13, LOW);
  // esperar 1000 milisegundos (1s)
  delay(1000);
}

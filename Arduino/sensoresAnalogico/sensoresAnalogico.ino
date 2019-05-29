// variável para ler o valor do sensor de luz
int valorSensor = 0;

void setup()
{
  // definir pino A0 como entrada
  pinMode(A0, INPUT);
  // iniciar monitor serial para ver o valor lido
  Serial.begin(9600);

  // definir pino do LED
  pinMode(9, OUTPUT);
}

void loop()
{
  // ler o valor registrado pelo sensor
  valorSensor = analogRead(A0);
  // exibir no monitor serial o valor obtido
  Serial.println(valorSensor);
  // mapear o valor do sensor (0-1023) para a intensidade o LED (0-255)
  analogWrite(9, map(valorSensor, 0, 1023, 0, 255));
  // esperar 100 milisegundos
  delay(100);
}

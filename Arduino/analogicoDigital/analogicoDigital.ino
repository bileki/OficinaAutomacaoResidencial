void setup() {
  // iniciar o monitor serial
  Serial.begin(9600);
  // definir o botão de pressão
  pinMode(2, INPUT_PULLUP);
  // definir o LED do Arduino como saída
  pinMode(13, OUTPUT);

}

void loop() {
  // ler o valor do botão
  int valorBotao = digitalRead(2);
  
  int valorPotenciometro = analogRead(A0);
  //print out the value of the pushbutton
  Serial.print("Botao: ");
  Serial.print(valorBotao);
  Serial.print(", Potenciometro: ");
  Serial.println(valorPotenciometro);

  // verificar se o botão está pressionado ou não para ligar o LED
  if (valorBotao == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
}

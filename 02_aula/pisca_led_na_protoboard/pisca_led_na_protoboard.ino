/*
Descrição: Testa se a placa do Arduino UNO com a protoboard (local onde insere os circuitos)
*/
int ledPin = 3; //Atribui o valor 3 a variável inteira ledPin, para que ela represente a porta digital D3 (GPIO3)
void setup() {
    pinMode(ledPin, OUTPUT); //Define ledPin (Pino D3) como saída
}
void loop() {
    digitalWrite(ledPin, LOW); //Coloca ledPin em nível lógico baixo, desligando o LED
    delay(1000); //Aguarda 1000 milissegundos (1 segundo)
    digitalWrite(ledPin, HIGH); //Coloca ledPin em nível lógico alto, ligando o LED
    delay(2000); //Aguarda 2000 milissegundos (2 segundos)
}

/*
Descrição: Testa se a placa do Arduino UNO com tecla
*/
int buttonPin = 5;//Atribui o pino digital D5 (GPIO5) à variável buttonPin 
int ledPin = 1;// Atribui o pino digital D1 (GPIO1) à variável ledPin 
int estadoButton = 0;//Variável responsável por armazenar o estado do botão (ligado/desligado)
void setup(){
    pinMode(ledPin , OUTPUT);//Define ledPin (pino 5) como saída
    pinMode(buttonPin , INPUT);//Define buttonPin (pino 1) como entrada
}
void loop(){
    estadoButton = digitalRead(buttonPin);//Lê o valor de buttonPin e armazena em estadoButton
    if (estadoButton == HIGH) {//Se estadoButton for igual a HIGH ou 1
        digitalWrite(ledPin , HIGH);//Define ledPin como HIGH, ligando o LED
        delay(100);//Intervalo de 100 milissegundos
    }
    else { //Senão = estadoButton for igual a LOW ou 0
        digitalWrite(ledPin, LOW);//Define ledPin como LOW, desligado o LED
    }
}

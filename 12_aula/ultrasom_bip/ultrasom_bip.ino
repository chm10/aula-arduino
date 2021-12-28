//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: FILIPEFLOP
// modified by Christian Maekawa
//Carrega a biblioteca do sensor ultrassonico
#include "Ultrasonic.h"
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
#define pino_buzzer 3
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  pinMode(pino_buzzer, OUTPUT);
}
 
void loop()
{
  //Le as informacoesec; do sensor, em cm e pol
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  //Exibe informacoes no serial monitor
  
    noTone(pino_buzzer); //Ligando o buzzer com uma frequência de 1500 Hz.
    delay(int(cmMsec*10 + 100)); //Intervalo de 500 milissegundos
    tone(pino_buzzer,1500); //Desligando o buzzer.
  if(cmMsec > 0.00){
    Serial.print("Distancia em cm: ");
    Serial.println(cmMsec);
  }
  delay(100);
  
}

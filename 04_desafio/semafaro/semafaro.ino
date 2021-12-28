/*
Desafio do semáfaro - Fazer um semáforo que o pedestre possa abertar um botão para conseguir liberar seu acesso e bloquear o acesso dos motoristas.
Dicas: Passe dicas a medida que for passando determinado tempo.
        Lembre que tudo que estiver no loop será executado infinitamente enquanto a placa estiver ligado, setup serve para inicializar variável uma vez. \
        Todas variáveis fora das funções são globais (elas são acessadas em todos os locais)
        Passe as variáveis do semáfaro.
        Expliquei sobre while(digitalRead(buttonPin)) enquanto o botão não estiver pressionado vai retornar falso e não entra na condição {}
        Explique sobre o for para utilizar para repetir determinada parte do código (Piscar 5 x o vermelho antes de fechar a faixa de pedestre) 
*/

int vermelhoCar = 3; //Define vermelhoCar no pino D3 (GPIO3) - vermelho dos carros
int amareloCar = 4; //Define amareloCar no pino D4 (GPIO4) - amarelo dos carros
int verdeCar = 5; //Define verdeCar no pino D5 (GPIO5) - verde dos carros
int buttonPin = 6; //Define buttonPin no pino D6 (GPIO6) - botão dos pedestres
int vermelhoPed = 7; //Define vermelhoPed no pino D7 (GPIO7) - vermelho dos pedestres
int verdePed = 8; //Define verdePed no pino D8 (GPIO8) - verde dos pedestres

void setup() {
    //Configura os pinos dos LEDs como saída e do botão como entrada
    pinMode(vermelhoCar, OUTPUT);
    pinMode(amareloCar, OUTPUT);
    pinMode(verdeCar, OUTPUT);
    pinMode(vermelhoPed, OUTPUT);
    pinMode(verdePed, OUTPUT);
    pinMode(buttonPin, INPUT);
}
void loop() {
    while (digitalRead(buttonPin)) { //Enquanto o botão não for pressionado
        digitalWrite(verdeCar, HIGH); //Liga o LED verde dos carros
        digitalWrite(vermelhoPed, HIGH); //Liga o LED vermelho dos pedestres
    }
//instruções que serão realizadas quando o botão for pressionado
    delay(2500); //Intervalo de 2,5 segundos
    digitalWrite(verdeCar, LOW); //Desliga o LED verde dos carros
    digitalWrite(amareloCar, HIGH); //Liga o LED amarelo dos carros
    delay(2500); //Intervalo de 2,5 segundo
    digitalWrite(amareloCar, LOW); //Desliga o LED amarelo dos carros
    digitalWrite(vermelhoCar, HIGH); //Liga o LED vermelho dos carros
    delay(2500); //Intervalo de 2,5 segundo
    digitalWrite(vermelhoPed, LOW); //Desliga o LED vermelho dos pedestres
    digitalWrite(verdePed, HIGH); //Liga o LED verde dos pedestres
    delay(4000); //Intervalo de 4 segundos
    //Pisca LED vermelho dos Pedestres
    for (int i = 0; i <= 5; i++) { //fazer 5 vezes
        digitalWrite(vermelhoPed, !(digitalRead(vermelhoPed))); //Inverte o estado do LED vermelho dos pedestres
        delay(500); //Intervalo de 0,5 segundo
    }
    delay(500); //Intervalo de 0,5 segundo
    digitalWrite(verdePed, LOW); //Desliga o LED verde dos pedestres
    digitalWrite(vermelhoCar, LOW); //Desliga o LED vermelho dos pedestres
}

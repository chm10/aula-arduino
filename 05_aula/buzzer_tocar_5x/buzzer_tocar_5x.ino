/* 
Descrição: Código criado para tocar 5 x o buzzer

*/

int buzzer = 2;//Atribui o valor 2 à variável buzzer, que representa o pino digital D2 (GPIO2), onde o buzzer está conectado
int i = 0;//Variável para contar o número de vezes que o buzzer tocou

void setup() {
    pinMode(buzzer, OUTPUT);//Definindo o pino buzzer como de saída.
}
void loop() {
    for (i; i < 5; i++) { //Para i, enquanto i for menor que 5, realize o código e incremente 1 em i
        tone(buzzer, 1500); //Ligando o buzzer com uma frequência de 1500 Hz.
        delay(500); //Intervalo de 500 milissegundos
        noTone(buzzer); //Desligando o buzzer.
        delay(500); //Intervalo de 500 milissegundos
    }
}

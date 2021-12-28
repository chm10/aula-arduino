/*
Descrição: Testa se a placa do Arduino UNO está gravando o programa desenvolvido.
*/
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);// Inicializa a variável LED_BUILTIN pino como modo saida (exibir)
}
void loop() {
    digitalWrite(LED_BUILTIN, LOW);// Liga o LED, LOW significa baixa voltagem
    // essa lógica só vale para o LED da  plaquinha
    // Isso porque o LED da placa denominado ESP-01 liga com baixa voltagem 
    // Internamente a lógica do circuito está invertendo o modo de ligar
    delay(1000);// Espera por um segundo 
    digitalWrite(LED_BUILTIN, HIGH);// Desliga o LED e faz voltagem ficar alta
    delay(2000);// Espera por 2 segundos (para mostrar que o LED está desligado com voltagem baixa)
}

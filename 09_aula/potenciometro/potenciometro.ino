int ledPin = 3;//Atribui o pino D3 (GPIO3) a variável ledPin
int potPin = A0;//Atribui o pino analógico A0 a variável potPin
int valorpot = 0;//Variável responsável pelo armazenamento da leitura bruta do potenciometro
int pwm = 0;//Variável responsável pelo armazenamento do valor convertido pela função map
void setup(){
 pinMode(ledPin, OUTPUT);//Configura ledPin como saída
 pinMode(potPin, INPUT);//Configura potPin como entrada
 Serial.begin(9600);//Inicializa a serial com velocidade de comunicação de 9600.
}
void loop(){
 valorpot = analogRead(potPin);//Efetua a leitura do pino analógico A0
 pwm = map(valorpot, 0, 1023, 0, 255);//Função map() para converter a escala de 0 a 1023 para a escala de 0 a 255
 Serial.println(pwm);//Imprime valorpot na serial
 analogWrite(ledPin, pwm);//Aciona o LED proporcionalmente à leitura analógica
 delay(500);//Intervalo de 500 milissegundos
}

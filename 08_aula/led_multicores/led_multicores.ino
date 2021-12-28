int vermelho = 2;//Atribui o valor 2 (pino D2) a variável azul
int verde = 3;//Atribui o valor 3 (pino D3) a variável verde
int azul = 4;//Atribui o valor 4 (pino D4) a variável vermelho
char cor;
void setup() {
	pinMode(azul, OUTPUT);//Define a variável azul como saída
	pinMode(verde, OUTPUT);//Define a variável verde como saída
	pinMode(vermelho, OUTPUT);//Define a variável vermelho como saída
	Serial.begin(9600);//Inicaliza a comunicação serial
}
//Função para acionamento da cor vermelho
void Vermelho() {
	digitalWrite(verde, LOW);
	digitalWrite(azul, LOW);
	digitalWrite(vermelho, HIGH);
}
//Função para acionamento da cor verde
void Verde() {
	digitalWrite(verde, HIGH);
	digitalWrite(azul, LOW);
	digitalWrite(vermelho, LOW);
}
//Função para acionamento da cor azul
void Azul() {
	digitalWrite(verde, LOW);
	digitalWrite(azul, HIGH);
	digitalWrite(vermelho, LOW);
}
//Função para acionamento da cor branca
void Branco() {
	digitalWrite(azul, HIGH);
	digitalWrite(vermelho, HIGH);
	digitalWrite(verde, HIGH);
}
//Função para acionamento da cor magenta
void Magenta() {
	digitalWrite(azul, HIGH);
	digitalWrite(vermelho, HIGH);
	digitalWrite(verde, LOW);
}
//Função para acionamento da cor amarela
void Esmeralda() {
	digitalWrite(verde, HIGH);
	digitalWrite(vermelho, HIGH);
	digitalWrite(azul, LOW);
}
//Função para acionamento da cor ciano
void Ciano() {
	digitalWrite(verde, HIGH);
	digitalWrite(azul, HIGH);
	digitalWrite(vermelho, LOW);
}
//Função desligado
void Desligado() {
	digitalWrite(verde, LOW);
	digitalWrite(vermelho, LOW);
	digitalWrite(azul, LOW);
} 
void loop() {
	if (Serial.available()) {//Se a serial receber algum caractere 
		char antiga_cor = cor;
		cor = Serial.read();//Lê os dados recebidos na porta serial e guarda na variável cor
		if(cor == '\n')// \n significa pular linha. Como você pode inserir o texto apertar enter pode vir na próxima vez um \n e precisamos ignorar ele
			cor = antiga_cor;//Se for um caracter de pular linha mantem a cor antiga dessa forma o led permanece acesso
		Serial.println(cor);//Imprime na porta serial o dado digitado pelo usuário
	}
	switch (cor) {
		case '1':
 		Vermelho();//Executa a função Vermelho
 		break;
 		case '2':
 		Verde();//Executa a função Verde
 		break;
 		case '3':
 		Azul();//Executa a função Azul
 		break;
 		case '4':
 		Branco();//Executa a função Branco
 		break;
 		case '5':
 		Magenta();//Executa a função Magenta
 		break;
 		case '6':
 		Esmeralda();
 		break;
 		case '7':
 		Ciano();//Executa a função Ciano
 		break;
		default:
 		Desligado();
 		break;
	}
}

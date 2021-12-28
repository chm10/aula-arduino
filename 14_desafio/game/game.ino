#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
bool alfabeto[26];
char palavra[16];
int tamanho_da_palavra;
byte coracao[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};
void menu_inicial(){
  lcd.setCursor(0, 0);
  lcd.print("Jogo de adivinha");
  lcd.setCursor(0, 1);
  lcd.print("comando 1 ou 2");  
}
bool preparado;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.createChar(1, coracao);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  menu_inicial();
  preparado = false;
}

void gravar_palavra(){
    char caracter;
    int novo_index = 0;
    lcd.setCursor(0,0);
    while (Serial.available()){
       caracter = Serial.read();//Lê os dados recebidos na porta serial e guarda na variável cor
    }
    caracter = ' ';
    lcd.print("Digite a palavra!");
    while(novo_index < 16) {//Se a serial receber algum caractere 
        if (Serial.available()){
         caracter = Serial.read();//Lê os dados recebidos na porta serial e guarda na variável cor
         if (caracter != '\n' and novo_index < 16){
          palavra[novo_index++] = caracter;
          tamanho_da_palavra = novo_index;
         }else{
          while(novo_index < 16)
            palavra[novo_index++] = ' '; 
         }
        }
      }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Jogo preparado!");
    for (int i = 0 ; i < 3 ; i++){
      lcd.noDisplay();
      delay(500);
      lcd.display();
      delay(500);
    }
    lcd.clear();
    menu_inicial();
    
}

const bool GANHOU = true;
bool checar_se_ganhou(){
    for (int i = 0 ; i < tamanho_da_palavra; i++){
        int index = int(palavra[i] - 'a');
        if (alfabeto[index] == false){
            return false;  
        }
    }
    return true;
}
void imprimi_palavra(){
    lcd.setCursor(0, 0);
    for (int i =0 ; i < tamanho_da_palavra ; i++){
        int index = palavra[i] - 'a';
        if(alfabeto[index]){
            lcd.print(palavra[i]);
        }
        else{
            lcd.print('_');  
        }
    }
}
void imprimi_tentativas(int vidas){
      lcd.setCursor(0,1);
      lcd.print("Voce tem ");
      lcd.print(vidas);
      lcd.print(" vidas!");  
}
bool checar_se_acertou(char chute){
    for (int i = 0 ; i < tamanho_da_palavra; i++){
        if(palavra[i] == chute){
          return false;  
        }
    }  
    return true;
}
bool jogar(){
    int tentativa = 5;
    for (int i = 0 ; i < 26; i++){
        alfabeto[i] = false;
    }
    lcd.setCursor(0, 0);
    lcd.print("Chute uma letra");
    lcd.clear();
    while (tentativa > 0){

        imprimi_palavra();
        imprimi_tentativas(tentativa);
        if (Serial.available()){
              char caracter = Serial.read();
              if (caracter!='\n'){
                  int index = int(caracter - 'a');
                  alfabeto[index] = true;
                  if(checar_se_acertou(caracter)){
                      tentativa--;
                  }
                  bool check = checar_se_ganhou();
                  if(check){
                    lcd.clear();
                    return true;
                  }
              }
              
        }
    }
    lcd.clear();
    return false; 
}

void loop() {
  // put your main code here, to run repeatedly:
  char opcao;
  if (Serial.available()) {//Se a serial receber algum caractere 
       opcao = Serial.read();//Lê os dados recebidos na porta serial e guarda na variável cor
       switch (opcao){
            case '1':
            lcd.clear();
            gravar_palavra();
            preparado = true;  
            break;
            case '2':
                if (preparado){
                  lcd.clear();
                  if (jogar() == GANHOU){
                      lcd.print("Adivinhador");
                      lcd.setCursor(0,1);
                      lcd.print("ganhou!");
                  }else{
                      lcd.print("Adivinhador"); 
                      lcd.setCursor(0,1);
                      lcd.print("perdeu!");
                  }
                }
                else{
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("Execute 1 antes");
                  delay(1000);
                  menu_inicial();
                }
            break;
            default:
            
            break;
       }
  }
}

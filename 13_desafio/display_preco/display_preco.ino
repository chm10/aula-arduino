/*
  LiquidCrystal Library - display() and noDisplay()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 display() and noDisplay() functions to turn on and off
 the display.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi
 modified 19 Dec 2021
 by Christian Maekawa

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay

*/

// include the library code:
#include <LiquidCrystal.h>
String data="";
// iInicializa o dispositivo com as portas necessarias
// Cada variável terá um número que significa a porta
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//https://maxpromer.github.io/LCD-Character-Creator/ para criar seu caracter
byte customChar[] = {
  B00000,
  B00000,
  B01110,
  B10001,
  B10000,
  B10001,
  B01110,
  B00100
};
char nome_do_produto[16]= {"1 Kg de Peixe"};
float quanto_custa = 10.0;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  lcd.createChar(1, customChar);
  tela_principal();
}
void limpar_tela(){
  lcd.setCursor(0,0);
  lcd.clear();  
}
void tela_principal(){
    lcd.setCursor(0,0); 
    lcd.print("Bem-vindo ao ");
    lcd.setCursor(0,1);
    lcd.print("sistema de pre");
    lcd.setCursor(14,1);
    lcd.write(1);
    lcd.setCursor(15,1);
    lcd.print("o");
    for (int i = 0 ; i < 3; i++){
      lcd.noDisplay();
      delay(500);
      // Turn on the blinking cursor:
      lcd.display();
      delay(500);
    }
}
void mostra_tela(){
      lcd.setCursor(0,0);
      lcd.print(nome_do_produto);
      lcd.setCursor(0,1);
      lcd.print("R$ ");
      lcd.setCursor(3,1);
      lcd.print(quanto_custa);
}
void exibe_msg(String var){
      limpar_tela();
      lcd.setCursor(0,0);
      lcd.print("Aguardando...");
      lcd.setCursor(0,1);
      lcd.print(var);
}
void exibe_ok(){
      limpar_tela();
      lcd.print("Atualizado!");
      for (int i = 0 ; i < 3; i++){
        lcd.noDisplay();
        delay(500);
        // Turn on the blinking cursor:
        lcd.display();
        delay(500);

      }    
      mostra_tela();     
}
void exibe_texto(String texto){
      limpar_tela();
      lcd.print(texto);
      for (int i = 0 ; i < 3; i++){
        lcd.noDisplay();
        delay(500);
        // Turn on the blinking cursor:
        lcd.display();
        delay(500);

      }    
      mostra_tela();     
}
void atualizar_nome(){
    exibe_msg("Nome de Produto");
    char caracter = ' ';    
    int novo_index = 0;
    while (Serial.available()){
       caracter = Serial.read();//Lê os dados recebidos na porta serial e guarda na variável cor
    }
    caracter = ' ';
    while(novo_index < 16) {//Se a serial receber algum caractere 
      if (Serial.available()){
       caracter = Serial.read();//Lê os dados recebidos na porta serial e guarda na variável cor
       if (caracter != '\n' and novo_index < 16){
        nome_do_produto[novo_index++] = caracter;
       }else{
        while(novo_index < 16)
          nome_do_produto[novo_index++] = ' '; 
       }
      }
    }
    exibe_ok();
}
bool verifica_digito(char caracter){
    int numero = int(caracter - '0');
    if ((numero >= 0 and numero <=9) or (caracter == '.')){
        return true;  
    }else{
        return false;
    }
}
void atualizar_preco(){
    exibe_msg("Adicione valor");
    char temp[16];
    char caracter = ' ';    
    int novo_index = 0;
    int virgula_inserida = false;
    while (Serial.available()){
       caracter = Serial.read();//Lê os dados recebidos na porta serial e guarda na variável cor
    }
    caracter = ' ';
    while(novo_index < 16) {//Se a serial receber algum caractere 
      if (Serial.available()){
       caracter = Serial.read();//Lê os dados recebidos na porta serial e guarda na variável cor
       if (caracter == ',')
          caracter = '.';
       if (caracter != '\n' and novo_index < 16 and verifica_digito(caracter)){
          if (!virgula_inserida){ 
              temp[novo_index++] = caracter;
          }else{
                if(novo_index!=0 and !virgula_inserida){
                    virgula_inserida = true;
                    temp[novo_index++] = caracter;  
                }else if(caracter != '.'){
                    temp[novo_index++] = caracter;
                }
          }
       }else{
        while(novo_index < 16)
          temp[novo_index++] = ' '; 
       }
      }
    }
    quanto_custa = atof(temp);
    exibe_ok();
}
void aplicar_10_porcento_ganho(){
     quanto_custa = quanto_custa*1.1;
}
void aplicar_10_porcento_desconto(){
     quanto_custa = quanto_custa*0.9;
}
char opcao;
void loop() {
   if (Serial.available()) {//Se a serial receber algum caractere 
       opcao = Serial.read();//Lê os dados recebidos na porta serial e guarda na variável cor
       switch (opcao){
            case '1':
            limpar_tela();
            tela_principal();
            break;
            case '2':
            limpar_tela();
            mostra_tela();
            break;
            case '3':
            limpar_tela();
            atualizar_nome();
            break;
            case '4':
            limpar_tela();
            atualizar_preco();
            break;
            case '5':
            limpar_tela();
            aplicar_10_porcento_ganho();
            exibe_texto("Ganho Aplicado!");
            limpar_tela();
            mostra_tela();
            break;
            case '6':
            limpar_tela();
            aplicar_10_porcento_desconto();
            exibe_texto("Desc. Aplicado!");
            limpar_tela();
            mostra_tela();
            break;
            default:
            printf("Funcionando");
            break;
       }
  }
}

//Programa: Teste de Display LCD 16 x 2
//Alteração/revisão: Arduino e Cia
#include <LiquidCrystal.h> //Carrega a biblioteca LiquidCrystal
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  //Define o número de colunas e linhas do LCD:
  lcd.begin(16, 2);
  //Envia o texto entre aspas para o LCD :
  lcd.print("Ola Pessoa");
}
void loop()
{
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(500);
  //Insira aqui o código para alterar
  //o texto, gerar efeito "blink" (piscar), etc.
}

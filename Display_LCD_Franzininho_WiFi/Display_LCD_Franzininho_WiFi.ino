/*
 * Autor : Halysson Jr
 * Data:   08/10/21
 * Programa: Auxilar no conhecimento teórico sobre
  o funcionamento do display LCD 16x2. Nesse projeto
  vamos apresentar os comandos básicos para escreve os
  dados no display sem necessitar de uma biblioteca
  externa
 
*/
#include "LCD_Display.h" /* Arquivo de cabeçalho para a inclusão do*/
 
void setup() {
  LCD_Iniciar();
  LCD_Comando(LCD_Clear );
  LCD_Saida_String(1,2, "FRANZININHO");
  LCD_Saida_String(2,5, "WIFI");
  delay (1000);
}

void loop() {

}

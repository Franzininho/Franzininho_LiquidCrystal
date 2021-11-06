/*
 * Autor : Halysson Jr
 * Data:   08/10/21
 * Programa: Auxilar no conhecimento teórico sobre
  o funcionamento do display LCD 16x2. Nesse projeto
  vamos apresentar os comandos básicos para escreve os
  dados no display sem necessitar de uma biblioteca
  externa
 
*/
#include "Franzininho_LiquidCrystal.h" /* Arquivo de cabeçalho para a inclusão do*/

Franzininho_LiquidCrystal FranzininhoWifi (3,2,1,0,4,5); /* Construtor */

void setup() {
  FranzininhoWifi.LCD_Iniciar();
  FranzininhoWifi.LCD_Comando(LCD_Clear);
  FranzininhoWifi.LCD_Saida_String(1,2, "FRANZININHO");
  FranzininhoWifi.LCD_Saida_String(2,5, "WIFI");
  delay (1000);
}

void loop() {

}

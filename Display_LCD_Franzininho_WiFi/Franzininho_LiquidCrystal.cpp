/*
 Arquivo que contém as funções implementadas para realizar a escritas de dados
 entre o microcontrolador e o Display LCD 16x2

*/
#include "Franzininho_LiquidCrystal.h" /* Arquivo de cabeçalho para referenciar os prótipos de funções e as definifições solicidas*/

Franzininho_LiquidCrystal::Franzininho_LiquidCrystal(uint8_t bit_4, uint8_t bit_5, uint8_t bit_6,
                                       uint8_t bit_7,uint8_t rs_ctrl_pino, uint8_t en_ctrl_pino){
                           
      LCD_Iniciar (bit_4,bit_5,bit_6,bit_7,rs_ctrl_pino,en_ctrl_pino);
}



void Franzininho_LiquidCrystal::LCD_Habilita(void){
  digitalWrite ( LCD_PINO_EN, LOW);
  delayMicroseconds(1);
  digitalWrite ( LCD_PINO_EN, HIGH);
  delayMicroseconds(1);
  digitalWrite ( LCD_PINO_EN, LOW);
  delay(100);
}/*fim LCD_Habilita*/

void Franzininho_LiquidCrystal::LCD_Escreve_Nibble( unsigned char dado){
  /*
    Exemplo de dado de entrada
    0011 1101 -> shif right -> 0000 0011
    
  */
  
  for (int f = 0; f < 4; f++) {
    digitalWrite(bit_pino[f], (dado >> f) & 0x01);
  }
  LCD_Habilita();
  
}

void Franzininho_LiquidCrystal::LCD_Iniciar (uint8_t lcd_bit4,uint8_t lcd_bit5,uint8_t lcd_bit6,
                                             uint8_t lcd_bit7,uint8_t lcd_pino_rs,uint8_t lcd_pino_en){
  
/* Configurar os pinos conectados ao LCD como saída digital e nível lógico zero*/

   bit_pino[0] =  lcd_bit4;
   bit_pino[1] =  lcd_bit5;
   bit_pino[2] =  lcd_bit6;
   bit_pino[3] =  lcd_bit7;

   LCD_PINO_RS = lcd_pino_rs;
   LCD_PINO_EN = lcd_pino_en;
   
   for(uint8_t f = 0 ; f < 4; f++){pinMode(bit_pino[f], OUTPUT);} 

   pinMode(LCD_PINO_EN, OUTPUT); 
   pinMode(LCD_PINO_RS, OUTPUT); 

   delayMicroseconds(50000);
   
   digitalWrite(LCD_PINO_RS, LOW);
   digitalWrite(LCD_PINO_EN, LOW);
  
   /* Configurar  o display para modo 4 bits */
 
    LCD_Escreve_Nibble(LCD_Inicializar);
    delayMicroseconds(4500);
    
    LCD_Escreve_Nibble(LCD_Inicializar);
    delayMicroseconds(4500);
    
    LCD_Escreve_Nibble(LCD_Inicializar);
    delayMicroseconds(150);

    LCD_Escreve_Nibble(LCD_Curso_Home);

    delay(1);

    LCD_Comando(0x28);
    LCD_Comando(0x0C);
    LCD_Comando(0x01);
    LCD_Comando(0x06);
    
}/* fim Display_Iniciar*/

void Franzininho_LiquidCrystal::LCD_Escreve_Dado( unsigned char dado){
   
   LCD_Envia_Dado (dado, 1);
   
} /* fim LCD_Escreve_Dado*/


void Franzininho_LiquidCrystal::LCD_Envia_Dado(unsigned char dado, uint8_t modo){
  /*
     Modo = 1 (Escreve dado)
     Modo = 0 (Carregar dado)
  */
 
 digitalWrite(LCD_PINO_RS,modo);
 LCD_Escreve_Nibble (dado >>4);   /* Recebe LSB */
 LCD_Escreve_Nibble (dado);       /* Recebe MSB */
  
}/*fim LCD_Envia_Dado*/

void Franzininho_LiquidCrystal::LCD_Comando(unsigned char comandoLCD){

     LCD_Envia_Dado(comandoLCD,0 ); //RS = 0 -> DADO A SER CARREGADO

}/* fim Display_Comando*/


void Franzininho_LiquidCrystal::LCD_Saida_Cp_Char (char caracter){
   
  LCD_Envia_Dado(caracter,1);  //RS = 1 -> DADO A SER ESCRITO

}/*fim Display_Saida_Cp_Char*/


void Franzininho_LiquidCrystal::LCD_Saida_Cp(char *ponteiro){

 /* Até encontrar o caracter NULL */ 
  do {
      LCD_Envia_Dado (*ponteiro,1 );
      ++ponteiro;
  }

  while(*ponteiro);
}/* fim Display_Saida_Cp*/

void Franzininho_LiquidCrystal::LCD_Saida_Char(uint8_t linha, uint8_t coluna, char caracter){
    

/* Primeiro colocamos o cursor na posição desejada e depois escrevemos o texto*/

 switch (linha){
  
  case 1: 
   coluna  = coluna + 0x7F;
   
   LCD_Envia_Dado(coluna,0);
  break;

  
  case 2:
   coluna  = coluna + 0xBF;
   LCD_Envia_Dado(coluna,0);
  break;
  
  default:
  break; 
  
  }/* fim switch */
  
  LCD_Saida_Cp_Char (caracter);
  
} /* fim Display_Saida_Caracter */
void Franzininho_LiquidCrystal::LCD_Saida_String(uint8_t linha, uint8_t coluna, char *texto){
    

/* Primeiro colocamos o cursor na posição desejada e depois escrevemos o texto */
 switch (linha){
  
  case 1: 
   coluna  = coluna + 0x7F;
   
   LCD_Envia_Dado(coluna,0);
  break;

  
  case 2:
   coluna  = coluna + 0xBF;
   LCD_Envia_Dado(coluna,0);
  break;
  
  default:
  break; 
  
  }/* fim switch*/
  
  LCD_Saida_Cp (texto);
  
} /* fim Display_Saida_String */

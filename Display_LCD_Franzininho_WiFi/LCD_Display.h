#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H
#include <Arduino.h>
// Definições 

#define LCD_Clear             (0x01)
#define LCD_Shift_LEFT        (0x18)
#define LCD_Shift_Right       (0x1C)
#define LCD_Cursor_OFF        (0X0C)
#define LCD_Cursor_Blink      (0X0D)
#define LCD_Cursor_Alt        (0X0F)
#define LCD_Curso_Home        (0X02)
#define LCD_Inicializar       (0x03)


//     Pinos do LCD      Pinos da Franzininho

#define LCD_BIT_4         3
#define LCD_BIT_5         2
#define LCD_BIT_6         1
#define LCD_BIT_7         0
#define LCD_PINO_RS       5
#define LCD_PINO_EN       4


//Prótotipo de Funções

void LCD_Habilita(void);
void LCD_Envia_Dado(unsigned char dado,unsigned char modo);
void LCD_Comando(unsigned char comandoLCD);
void LCD_Iniciar();
void LCD_Saida_Cp(char *ponteiro);
void LCD_Saida_String (unsigned char linha, unsigned char coluna,char *texto);
void LCD_Saida_Char(unsigned char linha, unsigned char coluna, unsigned char caracter);


#endif

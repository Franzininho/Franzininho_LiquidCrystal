#ifndef FRANZININHO_LIQUIDCRYSTAL_H
#define FRANZININHO_LIQUIDCRYSTAL_H

#include "Arduino.h"
#include <inttypes.h>
#include "Print.h"

/* Lista de Comandos*/
#define LCD_Clear             (0x01)
#define LCD_Shift_LEFT        (0x18)
#define LCD_Shift_Right       (0x1C)
#define LCD_Cursor_OFF        (0X0C)
#define LCD_Cursor_Blink      (0X0D)
#define LCD_Cursor_Alt        (0X0F)
#define LCD_Curso_Home        (0X02)
#define LCD_Inicializar       (0x03)


class Franzininho_LiquidCrystal  { 
public:
Franzininho_LiquidCrystal(unsigned char bit_4, unsigned char bit_5, unsigned char bit_6,
                          unsigned char bit_7,unsigned char rs_ctrl_pino, unsigned char en_ctrl_pino);

void LCD_Iniciar ();
                  
void LCD_Saida_String(unsigned char linha, unsigned char coluna,  char *texto);
void LCD_Saida_Char(unsigned char linha, unsigned char coluna, unsigned char caracter);
void LCD_Comando(unsigned char comandoLCD);
void LCD_Escreve_Dado( unsigned char dado);
void LCD_Saida_Cp( char *ponteiro);
void LCD_Saida_Cp_Char ( unsigned char caracter);

private:

void LCD_Escreve_Nibble( unsigned char dado);
void LCD_Habilita(void);
void LCD_Envia_Dado(unsigned char dado,unsigned char modo);

unsigned char bit_pino[4];                                                 /*Vetor contendo os pinos de dados */
unsigned char LCD_PINO_RS, LCD_PINO_EN; 
};


#endif

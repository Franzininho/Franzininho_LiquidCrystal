#ifndef FRANZININHO_LIQUIDCRYSTAL_H
#define FRANZININHO_LIQUIDCRYSTAL_H

#include <Arduino.h>
/* Lista de Comandos*/
#define LCD_Clear             (0x01)
#define LCD_Shift_LEFT        (0x18)
#define LCD_Shift_Right       (0x1C)
#define LCD_Cursor_OFF        (0X0C)
#define LCD_Cursor_Blink      (0X0D)
#define LCD_Cursor_Alt        (0X0F)
#define LCD_Curso_Home        (0X02)
#define LCD_Inicializar       (0x03)


class Franzininho_LiquidCrystal { 
public:
Franzininho_LiquidCrystal(uint8_t bit_4, uint8_t bit_5, uint8_t bit_6,
                          uint8_t bit_7,uint8_t rs_ctrl_pino, uint8_t en_ctrl_pino);

void LCD_Iniciar (uint8_t lcd_bit4,uint8_t lcd_bit5,uint8_t lcd_bit6,
                  uint8_t lcd_bit7,uint8_t lcd_pino_rs,uint8_t lcd_pino_en);
                  
void LCD_Saida_String(uint8_t linha, uint8_t coluna,  char *texto);
void LCD_Saida_Char(uint8_t linha, uint8_t coluna,  char caracter);
void LCD_Comando(unsigned char comandoLCD);

private:

void LCD_Escreve_Nibble( unsigned char dado);
void LCD_Escreve_Dado( unsigned char dado);
void LCD_Saida_Cp( char *ponteiro);
void LCD_Habilita(void);
void LCD_Saida_Cp_Char ( char caracter);
void LCD_Envia_Dado(unsigned char dado, uint8_t modo);

uint8_t bit_pino[4];                                                 /*Vetor contendo os pinos de dados */
uint8_t LCD_PINO_RS, LCD_PINO_EN; 
};


#endif

/**
 * @file 2_Read_ADC.c
 * @author Yashwanth (256287) (yashwanthabhilash@outlook.com)
 * @brief Reading and converting ADC values
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<avr/io.h>
#include"2_Read_ADC.h"

/** \brief Reading and converting ADC values
    *
    * \param  channel no. of data type uint_8
    * \return ADC o\p
    *
    */
void InitADC()
{
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}
uint16_t ReadADC(uint8_t ch)
{
    ADMUX&=0xf8;//select ADC channel Ch must be 0-7
    ch=ch&0b00000111;
    ADMUX|=ch;
    ADCSRA|=(1<<ADSC); //start single conversion
    while(!(ADCSRA&(1<<ADIF)));
    ADCSRA|=(1<<ADIF);
    return(ADC);
}


#include<avr/io.h>

    /** \brief ADC quantization and sampling occurs here
            *
            * \param  channel number of data type uint_8
            * \return final ADC output
            *
            */
void InitADC()
{
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}
uint16_t ReadADC(uint8_t ch)
{
    //select ADC channel Ch must be 0-7
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    //start single conversion
    ADCSRA|=(1<<ADSC);
    //wait for conversion to complete
    while(!(ADCSRA&(1<<ADIF)));
    //cleanADIF by writing one
    ADCSRA|=(1<<ADIF);
    return(ADC);
}


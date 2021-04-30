/**
 * @file 4_UART.c
 * @author Yashwanth (256287) (yashwanthabhilash@outlook.com)
 * @brief USART registers configured and message displayed
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include"4_UART.h"

#define BAUD 9600
#define F_CPU 16000000ul
#define BAUD_PRESCALE ((F_CPU/(16ul*BAUD))-1)

long int i;

/** \brief  USART registers configured and message displayed
 *
 * \param none
 * \return none
 *
 */

void USART_init()
{
    UCSR0B=(1<<TXEN0);
    UCSR0C =(1<<UCSZ01)|(1<<UCSZ00);
    UBRR0L=(BAUD_PRESCALE);//Set BAUD RATE
    UBRR0H=(BAUD_PRESCALE>>8);
}

/** \brief display() diplays the corresponding temperature in the Serial Moniter
 *
 * \param an uint19_t data type variable containing ADC output
 * \return none
 *
 */
void display(uint16_t temp)
{
    if(temp<=200)
       {   unsigned char data[] = "Temperature: 20 deg celsius ";//print
           i=0;
           while(data[i]!=0)
           {
               while(!(UCSR0A &(1<<UDRE0)));//wait for empty transmitter buffer
                UDR0 =data[i];               //put data into buffer and  transmit to serial moniter
                i++;
           }
       }
      else if(temp>200 && temp<=500)
       {
        unsigned char data[] = "Temperature: 25 deg celsius "; 
        i=0;
        while(data[i]!=0)
           {
               while(!(UCSR0A &(1<<UDRE0)));
                UDR0 =data[i];             
                i++;
           }
       }
      else if(temp>500 && temp<=710)
        {
            unsigned char data[] = "Temperature: 29 deg celsius ";
            i=0;
            while(data[i]!=0)
           {
               while(!(UCSR0A &(1<<UDRE0)));
                UDR0 =data[i];               
                i++;
           }
        }
      else
         {
             unsigned char data[] = "Temperature: 30 deg celsius ";
             i=0;
             while(data[i]!=0)
           {
               while(!(UCSR0A &(1<<UDRE0)));
                UDR0 =data[i];           
                i++;
           }
         }
}


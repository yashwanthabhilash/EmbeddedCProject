/**
 * @file main.c
 * @author Yashwanth (256287)
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include<util/delay.h>
#include"1_LED_Switch.h"
#include"2_Read_ADC.h"
#include"3_PWM_Output.h"
#include"4_UART.h"


uint16_t temp;  //intializing temp
int main(void)
{
     /** @brief intializes and declares all required ports
      * 
      */
    port();
    while(1)
    {

       if(bit_is_clear(PIND, 0)) // check pin 0 of portD for passenger
        {

            if(bit_is_clear(PIND, 1)) // check pin 1 or portD for button
            {
                PORTB=0b00000001; //LED ON 
                _delay_ms(200);
                /** @brief ADC Configuration
                * 
                */
                InitADC();
                TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01); //Select fast OWM with MAX TOP and SET PWM in non inverting mode
                TCCR0B|=(1<<CS00);  //selecting No prescaling
                /** @brief Reads i/p to the channel
                *   @param ADC channel number used
                *   @return digital equvivalent
                */
                temp = ReadADC(0);
                USART_init();
                /** @brief compares temperature value and gives PWM o/p
                *   @param ADC value stored in temp variable
                */
                compare(temp);
                /** @brief dispaly messages in Serial Moniter
                 *  @param ADC value stored in temp variable
                 */
                display(temp);

            }
            else
            {
            PORTB=0b00000000; // LED OFF
             _delay_ms(200);

            }
        }
        else
        {
            PORTB=0b00000000; //LED OFF
            _delay_ms(200);

        }
    }
    return 0;
}

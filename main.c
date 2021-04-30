
#include <avr/io.h>
#include<util/delay.h>
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"


uint16_t temp;  //intializing temp
int main(void)
{
     /** @brief intializes and declares all required ports
      * 
      */
    port();
    while(1)
    {

       if(bit_is_clear(PIND, 0)) // checking if passenger is present or not by checking pin 0 of Port D
        {

            if(bit_is_clear(PIND, 1)) // checking if button pressed or not by checking pin 1 of port D
            {
                PORTB=0b00000001; //LED ON if passenger present and heater button pressed 
                _delay_ms(200);
                /** @brief ADC Configuration
                * 
                */
                InitADC();
                TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01); //Select fast OWM with MAX TOP and SET PWM in non inverting mode
                TCCR0B|=(1<<CS00);  //selecting No prescaling
                /** @brief Reads i/p to the channel, sampling & quantization process occurs
                *   @param ADC channel number used
                *   @return digital equalent of analog input signal
                */
                temp = ReadADC(0);
                USART_init();
                /** @brief compares temperature value and gives PWM output
                *   @param ADC value stored in temp variable
                */
                compare(temp);
                /** @brief dispaly messages in Serial Moniter using USART  
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


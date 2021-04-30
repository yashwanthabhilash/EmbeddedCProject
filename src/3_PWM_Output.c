#include<avr/io.h>

/** \brief compare() will control the PWM duty cycle as per temperature ADC value
 *
 * \param temp variable contains the ADC value read from temp sensor/potentiometer
 * \return none
 *
 */

void compare(uint16_t temp)
{
    if(temp<=200)
       {
           OCR0A=50;             // PWM Duty cycle: 20%
       }
      else if(temp>200 && temp<=500)
       {
        OCR0A=101;              //PWM Duty cycle: 40%
       }
      else if(temp>500 && temp<=710)
        {
            OCR0A=177;           //PWM Duty cycle: 70%
        }
      else
         {
             OCR0A=241;         //PWM Duty cycle: 95%
         }
}


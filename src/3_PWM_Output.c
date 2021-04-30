/**
 * @file 3_PWM_Output.c
 * @author Yashwanth (256287) (yashwanthabhilash@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<avr/io.h>
#include"3_PWM_Output.h"

/** \brief PWM duty cycle will be controlled as per temperature ADC values
 *
 * \param temp ADC value read from temp sensor/potentiometer stored
 * \return none
 *
 */

void compare(uint16_t temp)
{
    if(temp<=200)
       {OCR0A=50;}// PWM Duty cycle: 20%
    else if(temp>200 && temp<=500)
       {OCR0A=101;}//PWM Duty cycle: 40%
    else if(temp>500 && temp<=710)
        { OCR0A=177;}//PWM Duty cycle: 70%
    else
        {OCR0A=241;}//PWM Duty cycle: 95%
         
}


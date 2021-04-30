/**
 * @file 1_LED_Switch.c
 * @author Yashwanth (256287) (yashwanthabhilash@outlook.com)
 * @brief Initializing and declaring all the ports required
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include"1_LED_Switch.h"

/**
 * @brief Initializing and declaring all the ports required
 * \param non
 * \return void
 * 
 */

void port()
{
    DDRB=00000001; //port B data direction register bit selected
    DDRD  |= 0 << PIND0; //pin 0 of port d - input pin
    DDRD  |= 0 << PIND1; //pin 1 of port d - input pin
    PORTD |= 1 << PIND1; //pin 1 of port d - HIGH
    PORTD |= 1 << PIND0; //pin 0 of port d - HIGH
    DDRD|=(1<<DDD6); 
}


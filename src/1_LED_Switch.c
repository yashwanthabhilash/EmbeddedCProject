#include <avr/io.h>

    /** \brief intializes and declares all required ports
            *
            * \param non
            * \return void
            *
            */
void port()
{
    DDRB=00000001;
    DDRD |= 0 << PIND0; //making pin 0 of port d as input pin
    DDRD |= 0 << PIND1; //making pin 1 of port d as input pin
    PORTD |= 1 << PIND1;//making pin 1 of port d HIGH
    PORTD |= 1 << PIND0; //making pin 0 of port d HIGH
    DDRD|=(1<<DDD6);
}


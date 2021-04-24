#include <avr/io.h>
#include<util/delay.h>

int main(void)
{

    DDRB |= (1<<PB0); //Set B0=1 for LED
    DDRD &=~(1<<PD0); //clear D0
    PORTD|=(1<<PD0); //set D0
    DDRD &=~(1<<PD1); //clear D0
    PORTD|=(1<<PD1); //set D0


    while(1){
         if(!(PIND&(1<<PD0)) && !(PIND&(1<<PD1))) {
        PORTB|=(1<<PB0);
            }
        else if(!(PIND&(1<<PD0)) && (PIND&(1<<PD1))){
        PORTB&= ~(1<<PB0);
            }
        else if((PIND&(1<<PD0)) && !(PIND&(1<<PD1))){
        PORTB&= ~(1<<PB0);
            }
        else if((PIND&(1<<PD0)) && (PIND&(1<<PD1))){
        PORTB&= ~(1<<PB0);
            }
    }


    return 0;
}

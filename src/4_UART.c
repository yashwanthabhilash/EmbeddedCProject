#include <avr/io.h>
#define BAUD 9600
#define F_CPU 16000000ul
#define BAUD_PRESCALE ((F_CPU/(16ul*BAUD))-1)

long int i;

/** \brief  USART_int() configure USART registers
 *
 * \param none
 * \return none
 *
 */

void USART_init()
{
    //Enable transmitter
    UCSR0B=(1<<TXEN0);
    // Set 8 bit data for transmission
    UCSR0C =(1<<UCSZ01)|(1<<UCSZ00);
    //Set BAUD RATE
    UBRR0L=(BAUD_PRESCALE);
    UBRR0H=(BAUD_PRESCALE>>8);
}

/** \brief display() siplays the corresponding temperature inSerial Moniter
 *
 * \param an uint19_t data type variable containing ADC output
 * \return none
 *
 */
void display(uint16_t temp)
{
    if(temp<=200)
       {   unsigned char data[] = "Temperature: 20 deg celsius ";// prints string " Temperature: 20 deg celsius"
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
        unsigned char data[] = "Temperature: 25 deg celsius "; // prints string " Temperature: 25 deg celsius"
        i=0;
        while(data[i]!=0)
           {
               while(!(UCSR0A &(1<<UDRE0)));//wait for empty transmitter buffer
                UDR0 =data[i];             //put data into buffer and  transmit to serial moniter
                i++;
           }
       }
      else if(temp>500 && temp<=710)
        {
            unsigned char data[] = "Temperature: 29 deg celsius ";// prints string " Temperature: 29 deg celsius"
            i=0;
            while(data[i]!=0)
           {
               while(!(UCSR0A &(1<<UDRE0)));//wait for empty transmitter buffer
                UDR0 =data[i];               //put data into buffer and  transmit to serial moniter
                i++;
           }
        }
      else
         {
             unsigned char data[] = "Temperature: 30 deg celsius ";// prints string " Temperature: 30 deg celsius"
             i=0;
             while(data[i]!=0)
           {
               while(!(UCSR0A &(1<<UDRE0)));//wait for empty transmitter buffer
                UDR0 =data[i];           //put data into buffer and  transmit to serial moniter
                i++;
           }
         }
}


/* 
 * File:   analog.c
 * Author: murray
 *
 * Created on 18 February 2020, 5:12 AM
 */

#include "analog.h"



void adc_init( void )
{
    PORTA = 0;
    TRISA =  0b11111111; //all inputs
    ADCON0 = 0b00000000; //adc off, 3bits select channel    
    ADCON1 = 0b10000000; //adc format right justified, all adc inputs 
}

int analogRead( int port )
{
    ADCON0 = (port << 3) + 0x01;
    while( GO_DONE );
    return  ADRESH + ADRESL;
}


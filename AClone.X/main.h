/* 
 * File:   main.h
 * Author: murray
 *
 * Created on 14 February 2020, 1:15 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <xc.h>
    
#define OUTPUT  0
#define INPUT   1
#define LOW     0
#define HIGH    1

#ifdef _PIC16F819_H_  
    void delay( int millis)
    {
        int _delay = millis / 4; 
        //using a TMR20 for a delay, 8bit
        //setup tmr, for number of 1 to 10 milli to delay
        //osc is 4 mhz
        //use /32 prescale
        //from calculation, TMR0 value = 256 - (delay x oscf/prescaler)
        OPTION_REG = 0b00010100; //T0CON0 = 0b10000000;
        //T0CON1 = 01000101;
        TMR0 = 223;     //TMR0L = 223; 
        TMR0IE = 0;     //Clear the interupt
                       
        for(int i = 0; i < _delay; i ++)
        {
            while(!TMR0IF); //check if TMR0IF set 
            TMR0IE = 0;     //and clear for next cycle.
            //TMR0 = 223;
        }
    }
#endif   
#ifdef _PIC16F18856_H_
    void delay( int millis)
    {
        int _delay = millis / 4; 
        //using a TMR20 for a delay, 8bit
        //setup tmr, for number of 1 to 10 milli to delay
        //osc is 4 mhz
        //use /32 prescale
        //from calculation, TMR0 value = 256 - (delay x oscf/prescaler)
        T0CON0 = 0b10000000;
        T0CON1 = 0b01000101;
        TMR0L = 223; 
        TMR0IE = 0;     //Clear the TMR0 interupt flag
                       
        for(int i = 0; i < _delay; i ++)
        {
            while(!TMR0IF); //check if TMR0IF set 
            TMR0IE = 0;     //and clear for next cycle.
        }
    }
#endif
    
long map( long x, long in_min, long in_max, long out_min, long out_max)
{
    return ( x - in_min) * (out_max - out_min + 1) / (in_max - in_min - 1) + out_min;
}

void __interrupt() intCmd()
{
    //if(1){}
}
//STD arduino setup code
void setup( void );
//STD arduino loop code
void loop( void );


#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */


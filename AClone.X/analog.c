/* 
 * File:   analog.c
 * Author: murray
 *
 * Created on 18 February 2020, 5:12 AM
 */

#include "analog.h"
#include <xc.h>

#ifdef _PIC16F819_H_  
int  pwm_running = 0;
void init_pwm( int port )
{
    //for the pic16F818 there is only one port
    TRISB = 0b00000000;         //xor next time using port
    PR2 = 0x00;   //pwm period
    CCPR1L = 0x00;  //duty cycle
    CCP1CON = 0b00001100; //PWM for CCP and zero last two bits of duty cycle
}

//At this stage only use the first 8 bits of the duty cycle.
void analogWrite( int port, int value )
{
    if(!pwm_running)
    {
        init_pwm(port);
    }
    PR2 = 0xFF / 2;   //pwm period 
    CCPR1L = value;  //duty cycle
    CCP1CON = 0b00001100; //PWM for CCP and zero last two bits of duty cycle
}


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

#endif

#ifdef _PIC16F18856_H_ 
int  pwm_running = 0;
void init_pwm( int port )
{
    //for the pic16F818 there is only one port
    TRISB = 0b00000000;         //xor next time using port
    PR2 = 0x00;   //pwm period
    CCPR1L = 0x00;  //duty cycle
    CCP1CON = 0b00001100; //PWM for CCP and zero last two bits of duty cycle
}

//At this stage only use the first 8 bits of the duty cycle.
void analogWrite( int port, int value )
{
    if(!pwm_running)
    {
        init_pwm(port);
    }
    PR2 = 0xFF / 2;   //pwm period 
    CCPR1L = value;  //duty cycle
    CCP1CON = 0b00001100; //PWM for CCP and zero last two bits of duty cycle
}


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

#endif
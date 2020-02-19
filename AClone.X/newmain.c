/* 
 * File:   newmain.c
 * Author: murray
 *
 * Created on 14 February 2020, 12:50 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "serial.h"

//STD arduino setup code
void setup( void );
//STD arduino loop code
void loop( void );
//setup adc pins
void adc_init(void);

void __interrupt() intCmd()
{
    if()
}

/*
 * 
 */
int main(int argc, char** argv) {
    adc_init();
    serial_init(_9600);
    
    setup();

    while(1)
    {
        loop();
    }
    
    return (EXIT_SUCCESS);
}

void setup( void )
{
}

void loop( void )
{
    
}

#define AN0 0x00
#define AN1 0x01
#define AN2 0x02
#define AN3 0x03
#define AN4 0x04

void adc_init( void )
{
    PORTA = 0;
    TRISA =  0b11111111; //all inputs
    ADCON0 = 0b00000000; //adc off, 3bits select channel    
    ADCON1 = 0b10000000; //adc format right justified, all adc inputs 
}

int analog_read( int port )
{
    ADCON0 = (port << 3) + 0x01;
    while( GO_DONE );
    return  ADRESH + ADRESL;
}

int  pwm_running = 0;
void init_pwm( int port )
{
    //for the pic16F818 there is only one port
    TRISB = 0b00000000;         //xor next time using port
    PR2 = 0x00;   //pwm period
    CCPR1L = 0x00;  //duty cycle
    CCP1CON = 0b00001100; //PWM for CCP and zero last two bits of duty cycle
}

void analog_write( int port, int value )
{
    if(!pwm_running)
    {
        init_pwm(port);
    }
    PR2 = 0xFF / 2;   //pwm period 
    CCPR1L = value;  //duty cycle
    CCP1CON = 0b00001100; //PWM for CCP and zero last two bits of duty cycle
}

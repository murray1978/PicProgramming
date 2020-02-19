/* 
 * File:   newmain.c
 * Author: murray
 *
 * Created on 14 February 2020, 12:50 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "config.h"
#include "serial.h"
#include "analog.h"
#include "digital.h"




/*
 * 
 */
int main(int argc, char** argv) {
    OSCCON = 01100000;  //4Mhz clock
    
    //adc_init();
    //serial_init(_9600);
    
    setup();

    while(1)
    {
        loop();
    }
    
    return (EXIT_SUCCESS);
}

void setup( void )
{
    TRISB = 0;
    PORTB = 255;
}

#define ADCPIN 0
#define REST_VAL 140

void loop( void )
{
    //int pwmSignal = analogRead(0);
    //pwmSignal = map(pwmSignal, 0, 1024, 0, 255);
    //float volt = ((float)pwmSignal/255.0) * 5.0;
    
    //if( digitalRead(4))
    //{
       // analogWrite(ADCPIN, pwmSignal);
    //    delay(30);
    //}
    //else
    //{
    //    analogWrite(ADCPIN, REST_VAL);
    //}
    PORTB = 0;
    delay(500);
    //for(int x = 0; x < 1024; x++){
    //    for(int y = 0; y < 1024; y++)
     //   {
    //        asm("nop");
    //    }
    //}
    PORTB = 255;
    delay(500);
    
}


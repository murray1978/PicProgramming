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
#include "analog.h"
#include "digital.h"




/*
 * 
 */
int main(int argc, char** argv) {
    adc_init();
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
}

void loop( void )
{
    int pwmSignal = analogRead(0);
    pwmSignal = map(pwmSignal, 0, 1024, 0, 255);
    //float volt = ((float)pwmSignal/255.0) * 5.0;
    
    if( digitalRead())
    {
        analogWrite(ADCPIN, pwmSignal);
        delay(30);
    }
    else
    {
        analogWrite(ADCPIN, REST_VAL);
    }
}


/* 
 * File:   serial.c
 * Author: murray
 *
 * Created on 14 February 2020, 1:19 PM
 */
#include "serial.h"
#include <xc.h>

void serial_init(int baud)
{
    int error = 0;
    
    if(baud == _9600)
    {
        error = 0;
    }
    else if(baud == _1200)
    {
        error = 0;
    }
    if(error > 0) //something bad has happened
    {
        while(1);
    }
}


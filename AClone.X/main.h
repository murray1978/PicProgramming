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

#define OUTPUT  0
#define INPUT   1
#define LOW     0
#define HIGH    1


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


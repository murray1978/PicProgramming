/* 
 * File:   analog.h
 * Author: murray
 *
 * Created on 18 February 2020, 5:12 AM
 */

#ifndef ANALOG_H
#define	ANALOG_H


#ifdef	__cplusplus
extern "C" {
#endif

 //setup adc pins
void adc_init(void);
int analogRead( int );
void analogWrite( int, int );
    
#define AN0 0x00
#define AN1 0x01
#define AN2 0x02
#define AN3 0x03
#define AN4 0x04


#ifdef	__cplusplus
}
#endif

#endif	/* ANALOG_H */


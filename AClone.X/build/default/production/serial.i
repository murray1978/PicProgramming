# 1 "serial.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "serial.c" 2






# 1 "./serial.h" 1
# 21 "./serial.h"
    void serial_init( int);
# 7 "serial.c" 2


void serial_init(int baud)
{
    int error = 0;

    if(baud == 0)
    {
        error = 0;
    }
    else if(baud == 1)
    {
        error = 0;
    }
    if(error > 0)
    {
        while(1);
    }
}

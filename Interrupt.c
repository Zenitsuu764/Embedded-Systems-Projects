#include <xc.h>
#include "config.h"

#define _XTAL_FREQ 4000000

void main(void) {
    
    TRISC0 = 0;
    TRISC1 = 0;
    
    RC0 = 0;
    RC1 = 0;
    
    TRISB0 = 1;
    
    INTEDG = 1;
    
    INTE = 1;
    GIE = 1;
    
    
    while (1)
    {
        RC0 = 1;
    }
    
    return;
}

void __interrupt() ISR()
{
    if(INTF)
    {
        RC1 = ~RC1;
        INTF = 0;
    }
}
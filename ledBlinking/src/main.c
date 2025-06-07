#include "led.h"
#include "utils.h"

void main()
{
    *GPFSEL1 |= (1 << 18); // Set GPIO16 as output

    while(1)
	{
        *GPSET0 = (1 << 16); // Set GPIO16 high
        delay(500000);
        *GPCLR0 = (1 << 16); // Set GPIO16 low
        delay(500000);
    }
}

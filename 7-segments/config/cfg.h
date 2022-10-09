#pragma once

#ifndef __CFG__
#define __CFG__

#define vint volatile unsigned int

#define digit PORTB
#define data PORTC
#define Output 0xFF

#define pinModeB DDRB
#define pinModeC DDRC

#define OUTPUT 1
#define INPUT 0

int main(void);
void setup();
void loop();

int main(void)
{
        setup();
        while (1)
        {
                loop();
        }
}

#endif
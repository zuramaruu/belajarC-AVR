#ifndef __AVR_ATmega8535__
#define __AVR_ATmega8535__
#endif

#include "avr/io.h"
#define  F_CPU 1000000UL
#include "util/delay.h"

#define vchar    volatile unsigned char
#define NOL             0xC0
#define SATU            0xF9
#define DUA             0xA4
#define TIGA            0x30
#define EMPAT           0x19

#define LIMA            0x12
#define ENAM            0x02
#define TUJUH           0xB8
#define DELAPAN         0x00
#define SEMBILAN        0x10

#define DIG1            0x08
#define DIG2            0x04
#define DIG3            0x02
#define DIG4            0x01

int i;
char arr[] = {SATU};
char arr2[] = {SATU, DUA};
char arr3[] = {SATU, DUA, TIGA};
char arr4[] = {SATU, DUA, TIGA, EMPAT};
char ord[] = {DIG1};
char ord2[] = {DIG1, DIG2};
char ord3[] = {DIG1, DIG2, DIG3};
char ord4[] = {DIG1, DIG2, DIG3, DIG4};


uint8_t state = 0;
uint8_t j = 0, k = 0, l = 0;

int  main();
void setIO();
void loop();
void set(vchar *, char num,vchar *,  char pos);

int main(void) { setup(); while (1) { loop(); } }

void setup() {
	DDRB = 0xFF;
        DDRD = 0xFF;
}

void loop() {
        for (i = 0; i < 4; i++) {
                if (state < 1) set(&PORTD, arr[i], &PORTB , ord[i]);
                else if (state < 3) { set(&PORTD, arr2[j], &PORTB , ord2[j]);
                        j++;
                }
                else if (state < 6) { set(&PORTD, arr3[k], &PORTB , ord3[k]);
                        k++;
                }
                else if (state < 10) { set(&PORTD, arr4[l], &PORTB , ord4[l]);
                        l++;
                }
                _delay_ms(500);
                state++;
                if (state == 10) {
                        state = 0;
                        j = 0;
                        k = 0;
                        l = 0;
                }
        }
}

void set(vchar *port_x, char val, vchar *port_y, char pos) {
        *port_x = val;
        *port_y = pos;
}

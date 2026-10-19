/* Study example for Keil C51. Build with Dri_Timer0.c and Util.c.
 * This file has its own main; do not build it together with src/main.c.
 * Wiring and timer settings follow the current course board.
 */
#include <STC89C5xRC.H>
#include "Dri_Timer0.h"

static unsigned char code s_digit_codes[10] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66,
    0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

static volatile unsigned char s_seg_buffer[8];

/* Only the foreground calls this function. Keep the critical section short. */
static void SegPublish(unsigned char next[8])
{
    unsigned char i;
    bit saved_ea;

    saved_ea = EA;
    EA = 0;
    for (i = 0; i < 8; i++) {
        s_seg_buffer[i] = next[i];
    }
    EA = saved_ea;
}

/* Display scaled / 10^decimals, with 0..3 decimal places.
 * Examples: (-1234L, 2) -> -12.34; (5L, 1) -> 0.5.
 * Positive values have no sign. No rounding is performed here.
 * Return 1 on success. Invalid precision or overflow displays --------.
 * Call from the foreground, not from an interrupt callback.
 */
bit SegSetScaled(signed long scaled, unsigned char decimals)
{
    unsigned char next[8];
    unsigned char i;
    unsigned char digits;
    signed char pos;
    unsigned long magnitude;

    for (i = 0; i < 8; i++) {
        next[i] = 0x00;
    }
    if (decimals > 3) {
        goto overflow;
    }

    if (scaled < 0) {
        /* This also handles the 32-bit minimum value -2147483648. */
        magnitude = (unsigned long)(-(scaled + 1L)) + 1UL;
    } else {
        magnitude = (unsigned long)scaled;
    }

    pos = 7;
    digits = 0;
    do {
        if (pos < 0) {
            goto overflow;
        }
        next[(unsigned char)pos] = s_digit_codes[magnitude % 10UL];
        if (decimals != 0 && digits == decimals) {
            next[(unsigned char)pos] |= 0x80;
        }
        pos--;
        digits++;
        magnitude /= 10UL;
    } while (magnitude != 0 || digits <= decimals);

    if (scaled < 0) {
        if (pos < 0) {
            goto overflow;
        }
        next[(unsigned char)pos] = 0x40;
    }

    SegPublish(next);
    return 1;

overflow:
    for (i = 0; i < 8; i++) {
        next[i] = 0x40;
    }
    SegPublish(next);
    return 0;
}

/* Timer0 callback: one digit per tick, no delay, about 8 ms per frame. */
void SegScan1ms(void)
{
    static unsigned char pos = 0;

    P0 = 0x00;
    /* Use port read-modify-write instructions to preserve other latches. */
    P1 &= 0xC7;
    P1 |= (pos << 3);
    P0 = s_seg_buffer[pos];
    pos++;
    if (pos == 8) {
        pos = 0;
    }
}

void main(void)
{
    P0 = 0x00;
    P34 = 0;  /* Disable the LED module sharing P0. */
    P35 = 1;  /* Disable the matrix LED module sharing P0. */
    P36 = 0;  /* Enable the seven-segment display. */

    SegSetScaled(-1234L, 2);

    /* Init clears all callbacks, so register only after initialization. */
    Dri_Timer0_Init();
    EA = 0;
    if (!Dri_Timer0_RegisterCallback(SegScan1ms)) {
        P0 = 0x00;
        while (1) {
            ;
        }
    }
    EA = 1;

    while (1) {
        /* Handle keys or measurements here, then call SegSetScaled again. */
    }
}

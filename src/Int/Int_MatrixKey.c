#include "Int_MatrixKey.h"
#include <STC89C5xRC.H>

u8 Int_MatrixKey_CheckKey()
{
    //    P24 P25 P26 P27
    // P20 +---+---+---+
    // P21 +---+---+---+
    // P22 +---+---+---+
    // P23 +---+---+---+

    // 扫描第一行,将P20置0，其余置1；P27-P20依次为：1111 1110
    P2 = 0xFE;//1   1   1   1   1   1   1   0
              //P27 P26 P25 P24 P23 P22 P21 P20

    // 检测第SW5是否被按下,若被按下,P24会被拉低,P27-P20依次为:1110 1110
    if (P2 == 0xEE) {
        Delay1ms(10);
        if (P2 == 0xEE) {
            while (P2 == 0xEE);
            return 5;
        }
    }

    // 检测第SW6是否被按下,若被按下,P25会被拉低,P27-P20依次为：1101 1110
    if (P2 == 0xDE) {
        Delay1ms(10);
        if (P2 == 0xDE) {
            while (P2 == 0xDE);
            return 6;
        }
    }

    // 检测第SW7是否被按下,若被按下,P26会被拉低,P27-P20依次为：1011 1110
    if (P2 == 0xBE) {
        Delay1ms(10);
        if (P2 == 0xBE) {
            while (P2 == 0xBE);
            return 7;
        }
    }

    // 检测第SW8是否被按下,若被按下,P28会被拉低,P27-P20依次为：0111 1110
    if (P2 == 0x7E) {
        Delay1ms(10);
        if (P2 == 0x7E) {
            while (P2 == 0x7E);
            return 8;
        }
    }

    // 扫描第二行，将P21置0，其余置1；P27-P20依次为：1111 1101
    P2 = 0xFD;
    // 检测第SW9是否被按下,若被按下,P24会被拉低,P27-P20依次为：1110 1101
    if (P2 == 0xED) {
        Delay1ms(10);
        if (P2 == 0xED) {
            while (P2 == 0xED);
            return 9;
        }
    }

    // 检测第SW10是否被按下,若被按下,P25会被拉低,P27-P20依次为：1101 1101
    if (P2 == 0xDD) {
        Delay1ms(10);
        if (P2 == 0xDD) {
            while (P2 == 0xDD);
            return 10;
        }
    }

    // 检测第SW11是否被按下,若被按下,P26会被拉低,P27-P20依次为：1011 1101
    if (P2 == 0xBD) {
        Delay1ms(10);
        if (P2 == 0xBD) {
            while (P2 == 0xBD);
            return 11;
        }
    }

    // 检测第SW12是否被按下,若被按下,P28会被拉低,P27-P20依次为：0111 1101
    if (P2 == 0x7D) {
        Delay1ms(10);
        if (P2 == 0x7D) {
            while (P2 == 0x7D);
            return 12;
        }
    }

    // 扫描第三行，将P22置0，其余置1；P27-P20依次为：1111 1011
    P2 = 0xFB;
    // 检测第SW13是否被按下,若被按下,P24会被拉低,P27-P20依次为：1110 1011
    if (P2 == 0xEB) {
        Delay1ms(10);
        if (P2 == 0xEB) {
            while (P2 == 0xEB);
            return 13;
        }
    }

    // 检测第SW14是否被按下,若被按下,P25会被拉低,P27-P20依次为：1101 1011
    if (P2 == 0xDB) {
        Delay1ms(10);
        if (P2 == 0xDB) {
            while (P2 == 0xDB);
            return 14;
        }
    }

    // 检测第SW15是否被按下，若被按下，P26会被拉低，P27-P20依次为：1011 1011
    if (P2 == 0xBB) {
        Delay1ms(10);
        if (P2 == 0xBB) {
            while (P2 == 0xBB);
            return 15;
        }
    }

    // 检测第SW16是否被按下，若被按下，P28会被拉低，P27-P20依次为：0111 1011
    if (P2 == 0x7B) {
        Delay1ms(10);
        if (P2 == 0x7B) {
            while (P2 == 0x7B);
            return 16;
        }
    }

    // 扫描第四行，将P23置0，其余置1；P27-P20依次为：1111 0111
    P2 = 0xF7;
    // 检测第SW17是否被按下，若被按下，P24会被拉低，P27-P20依次为：1110 0111
    if (P2 == 0xE7) {
        Delay1ms(10);
        if (P2 == 0xE7) {
            while (P2 == 0xE7);
            return 17;
        }
    }

    // 检测第SW18是否被按下，若被按下，P25会被拉低，P27-P20依次为：1101 0111
    if (P2 == 0xD7) {
        Delay1ms(10);
        if (P2 == 0xD7) {
            while (P2 == 0xD7);
            return 18;
        }
    }

    // 检测第SW19是否被按下，若被按下，P26会被拉低，P27-P20依次为：1011 0111
    if (P2 == 0xB7) {
        Delay1ms(10);
        if (P2 == 0xB7) {
            while (P2 == 0xB7);
            return 18;
        }
    }

    // 检测第SW20是否被按下，若被按下，P28会被拉低，P27-P20依次为：0111 0111
    if (P2 == 0x77) {
        Delay1ms(10);
        if (P2 == 0x77) {
            while (P2 == 0x77);
            return 20;
        }
    }

    return 0;
}

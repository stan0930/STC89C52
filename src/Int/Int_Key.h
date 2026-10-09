#ifndef __INT_KEY_H__
#define __INT_KEY_H__

#include <STC89C5xRC.H>

/**
 * @brief 检测SW1按键是否按下
 *
 * @return bit 是或否
 */
bit Int_Key_IsSW1Pressed();

/**
 * @brief 检测SW2按键是否按下
 *
 * @return bit 是或否
 */
bit Int_Key_IsSW2Pressed();

/**
 * @brief 检测SW3按键是否按下
 *
 * @return bit 是或否
 */
bit Int_Key_IsSW3Pressed();

/**
 * @brief 检测SW4按键是否按下
 *
 * @return bit 是或否
 */
bit Int_Key_IsSW4Pressed();



#endif /* __INT_KEY_H__ */
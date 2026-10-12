#ifndef __INT_LED_H__
#define __INT_LED_H__

/* Initialize the running LEDs and register the Timer0 callback. */
void Int_Led_Init(void);

/* Called once per Timer0 overflow. */
void Int_Led_Show(void);

#endif /* __INT_LED_H__ */

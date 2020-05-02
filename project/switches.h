#ifndef switches_included
#define switches_included

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1|SW2|SW3|SW4)

extern char SW1_STATE, SW2_STATE, SW3_STATE, SW4_STATE;

extern char switch_state_changed;

void switch_init();
void switch_interrupt_handler();

#endif

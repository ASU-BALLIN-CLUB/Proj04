//
//  pit.h
//
//	Proj02
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

#includes"gpio.h"
#includes"global.h"
#includes"int.h"
#includes"uc_dipsw.h"
#includes"gpt.h"
#includes"oct_rgb_led.h"
#includes"pit.h"
#includes"pwm.h"
#includes"uc_pushb.h"

typedef enum {
 pit_timer_0 = 0, //
 pit_timer_1 = 1 //
} pit_timer_t;

static int_isr_t g_pit_callbacks[2] = {0};
static int_isr_t g_pit_isrs[2] = {pit0_isr , pit1_isr};

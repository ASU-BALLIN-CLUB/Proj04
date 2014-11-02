//
//  main.c
//
//	Proj04
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

#include"gpio.h"
#include"global.h"
#include"int.h"
#include"uc_dipsw.h"
#include"gpt.h"
#include"oct_rgb_led.h"
#include"pit.h"
#include"pwm.h"
#include"uc_pushb.h"
#include"uc_led.h"


typedef enum {
	flash_mode = 0,
	step_mode = 1
} mode_t;

static int led = 1;
static void hw_init();
static void pushb_1_callback();
static void run();
__declspec(noreturn) int main();

static void hw_init()
{
	int_inhibit_all();
	//oct_rgb_led_init();
	uc_dipsw_init();
	uc_led_init();
	uc_pushb_init(uc_pushb_1, pushb_1_callback);
	int_uninhibit_all();
}

static void pushb_1_callback()
{
	if (led == 1)
	{
		uc_led_on((gpio_pin_t)uc_led_2);
		led--;
	}
	else
	{
		uc_led_off((gpio_pin_t)uc_led_1);
		led++;
	}
}

static void run()
{
	mode_t state = (mode_t)uc_dipsw_get_state(uc_dipsw_1);
	while(1)
	{
		state = (mode_t)uc_dipsw_get_state(uc_dipsw_1);
		if(state == flash_mode)
		{
			oct_rgb_led_all_off();
			oct_rgb_led_init();
			while(state == flash_mode)
			{
				state = (mode_t)uc_dipsw_get_state(uc_dipsw_1);
				//pwm_chan_start(, uint8 const period, uint8 const duty)
			}
		}
	}
}

__declspec(noreturn) int main()
{
	hw_init();
 	run();
}

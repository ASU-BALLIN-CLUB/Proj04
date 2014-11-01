//
//  main.c
//
//	Proj04
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
	flash_mode = 1,
	step_mode = 0
} mode_t;

static void hw_init()
{
	int_inhibit_all();
	//oct_rgb_led_init();
	uc_dipsw_init();
	uc_pushb_init(uc_pushb_1, pushb_1_callback);
	int_uninhibit_all();
}

static void pushb_1_callback()
{

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
			while(state == flash_mode)
			{
				oct_rgb_led_init();
			}
		}
	}
}

__declspec(noreturn) int main()
{
	hw_init();
	run();
}

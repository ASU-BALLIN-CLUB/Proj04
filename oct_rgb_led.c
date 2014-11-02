//
//  oct_rgb_led.c
//
//	Proj02
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

#include "oct_rgb_led.h"

static oct_rgb_pin_t active_led = LED1_COM;
static bool_t LED1_FLAG = false;
static bool_t LED2_FLAG = false;
static bool_t LED3_FLAG = false;
static int LED1_COUNTER = 2;
static int LED2_COUNTER = 2;
static int LED3_COUNTER = 2;



static struct _color_duty_t {
	uint8 m_red;
	uint8 m_green;
	uint8 m_blue;
}	g_color_duty[] = {
	{202, 202, 160}, //blue
	{202, 139, 202}, //green
	{180, 202, 202}  //red
};

void oct_rgb_led_all_off()
{
	LED1_FLAG = false;
	LED2_FLAG = false;
	LED3_FLAG = false;
}

void oct_rgb_led_all_on()
{
	LED1_FLAG = true;
	LED2_FLAG = true;
	LED3_FLAG = true;
}

void oct_rgb_led_init()
{
	gpio_port_init(gpio_port_an, (gpio_pin_t)LED1_COM, gpio_funct_gpio, gpio_data_dir_out, gpio_pin_state_high);
	gpio_port_init(gpio_port_an, (gpio_pin_t)LED2_COM, gpio_funct_gpio, gpio_data_dir_out, gpio_pin_state_high);
	gpio_port_init(gpio_port_an, (gpio_pin_t)LED3_COM, gpio_funct_gpio, gpio_data_dir_out, gpio_pin_state_high);
	pwm_clk_config(clk_src_sa, 0, 100);
	pwm_clk_config(clk_src_sb, 0, 100);
	//void pwm_clk_config(clk_src_t const clk_src, uint8 const p_prescale, uint8 const p_scale)
	pwm_chan_init(pwm_channel_4, clk_src_sa, left_aligned, high_polarity);
	pwm_chan_init(pwm_channel_5, clk_src_sb, left_aligned, high_polarity);
	pwm_chan_init(pwm_channel_6, clk_src_sa, left_aligned, high_polarity);
	//void pwm_chan_init(pwm_channel_t const n, clk_src_t const clk_src,uint8 const align, uint8 const polarity)
	//oct_rgb_led_all_off();
	pit_init(pit_timer_0, 2, 49999, oct_rgb_led_callback);
	active_led = LED1_COM;
	//pit_init(pit_timer_t const n, uint8 const p_prescaler, uint16 const p_pmr ,int_isr_t const p_callback);
	pit_enable(pit_timer_0);

}

void oct_rgb_led_off(oct_rgb_led_t p_led)
{
	if(p_led == LED1_COM1)
	{
		LED1_FLAG = false;
	}
	else if(p_led == LED2_COM1)
	{
		LED2_FLAG = false;
	}
	else
	{
		LED3_FLAG = false;
	}
}

void oct_rgb_led_on(oct_rgb_led_t p_led)
{
	if(p_led == LED1_COM1)
	{
		LED1_FLAG = true;
	}
	else if(p_led == LED2_COM1)
	{
		LED2_FLAG = true;
	}
	else
	{
		LED3_FLAG = true;
	}
}

/*void oct_rgb_led_set_color(oct_rgb_led_t p_led, oct_rgb_led_color_t p_color)
{

}*/

void oct_rgb_led_toggle(oct_rgb_led_t p_led)
{
	if(p_led == LED1_COM1)
	{
		if(LED1_FLAG == true)
		{
			LED1_FLAG = false;
		}
		else
		{
			LED1_FLAG = true;
		}
	}
	else if(p_led == LED2_COM1)
	{
		if(LED2_FLAG == true)
		{
			LED2_FLAG = false;
		}
		else
		{
			LED2_FLAG = true;
		}
	}
	else
	{
		if(LED3_FLAG == true)
		{
			LED3_FLAG = false;
		}
		else
		{
			LED3_FLAG = true;
		}
	}
}

static void oct_rgb_led_callback()
{
	//void gpio_port_set_pin_state(gpio_port_t p_port, gpio_pin_t p_pin, gpio_pin_state_t p_state)

	if(active_led == LED1_COM)	//LED1
	{
		
		gpio_port_set_pin_state(gpio_port_an, gpio_pin_4, gpio_pin_state_low);
		gpio_port_set_pin_state(gpio_port_an, gpio_pin_6, gpio_pin_state_low);
		gpio_port_set_pin_state(gpio_port_an, gpio_pin_7, gpio_pin_state_low);
		oct_rgb_led_on(LED1_COM1);
		if(active_led == LED1_COM)
		{
			//void pwm_chan_start(pwm_channel_t const n, uint8 const period, uint8 const duty)
			
			//gpio_port_set_pin_state(gpio_port_an, gpio_pin_7, gpio_pin_state_high);
			pwm_chan_start(pwm_channel_4, (uint8)period_200, (uint8)period_202);
			pwm_chan_start(pwm_channel_5, (uint8)period_200, (uint8)period_202);
			pwm_chan_start(pwm_channel_6, (uint8)period_200, (uint8)period_100);
			uc_led_on((gpio_pin_t)uc_led_1);
			gpio_port_set_pin_state(gpio_port_an, gpio_pin_4, gpio_pin_state_high);
			if(LED1_COUNTER > 0)
			{
				LED1_COUNTER--;
			}
			else
			{
				LED1_COUNTER = 2;
			}
			//oct_rgb_led_off(LED1_COM1);
		}
		active_led = LED2_COM;
	}
	else if(active_led == LED2_COM)
	{
		gpio_port_set_pin_state(gpio_port_an, gpio_pin_4, gpio_pin_state_high);
		gpio_port_set_pin_state(gpio_port_an, gpio_pin_6, gpio_pin_state_low);
		gpio_port_set_pin_state(gpio_port_an, gpio_pin_7, gpio_pin_state_low);;
		oct_rgb_led_on(LED2_COM1);
		if(LED2_FLAG == true)
		{
			//void pwm_chan_start(pwm_channel_t const n, uint8 const period, uint8 const duty)

			pwm_chan_start(pwm_channel_4,  (uint8)period_200, (uint8)period_202);
			pwm_chan_start(pwm_channel_5,  (uint8)period_200, (uint8)period_100);
			pwm_chan_start(pwm_channel_6,  (uint8)period_200, (uint8)period_202);
			gpio_port_set_pin_state(gpio_port_an, gpio_pin_6, gpio_pin_state_high);
			if(LED2_COUNTER > 0)
			{
				LED2_COUNTER--;
			}
			else
			{
				LED2_COUNTER = 2;
			}
			oct_rgb_led_off(LED2_COM1);
		}
		active_led = LED3_COM;
	}
	else
	{
		gpio_port_set_pin_state(gpio_port_an, gpio_pin_4, gpio_pin_state_low);
		gpio_port_set_pin_state(gpio_port_an, gpio_pin_6, gpio_pin_state_low);
		gpio_port_set_pin_state(gpio_port_an, gpio_pin_7, gpio_pin_state_low);
		oct_rgb_led_on(LED3_COM1);
		if(LED3_FLAG == true)
		{
			//void pwm_chan_start(pwm_channel_t const n, uint8 const period, uint8 const duty)

			pwm_chan_start(pwm_channel_4,  (uint8)period_200, (uint8)period_100);
			pwm_chan_start(pwm_channel_5,  (uint8)period_200, (uint8)period_202);
			pwm_chan_start(pwm_channel_6,  (uint8)period_200, (uint8)period_202);
			gpio_port_set_pin_state(gpio_port_an, gpio_pin_7, gpio_pin_state_high);
			if(LED3_COUNTER > 0)
			{
				LED3_COUNTER--;
			}
			else
			{
				LED3_COUNTER = 2;
			}
			oct_rgb_led_off(LED3_COM1);
		}
		active_led = LED1_COM;
	}
}

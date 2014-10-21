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

void oct_rgb_led_all_off()
{

}

void oct_rgb_led_all_on()
{

}

void oct_rgb_led_init()
{
	gpio_port_init(gpio_port_an, (gpio_port_pin_t)LED1_COM, gpio_funct_gpio, gpio_data_dir_out, gpio_pin_state_low);
	gpio_port_init(gpio_port_an, (gpio_port_pin_t)LED2_COM, gpio_funct_gpio, gpio_data_dir_out, gpio_pin_state_low);
	gpio_port_init(gpio_port_an, (gpio_port_pin_t)LED3_COM, gpio_funct_gpio, gpio_data_dir_out, gpio_pin_state_low);
	pwm_clk_config(clk_src, p_prescale, p_scale)
	pwm_clk_config(clk_src, p_prescale, p_scale)
	//void pwm_clk_config(clk_src_t const clk_src, uint8 const p_prescale, uint8 const p_scale)
	void pwm_chan_init(n, clk_src_sa, align, polarity)
	void pwm_chan_init(n, clk_src_sb, align, polarity)
	//void pwm_chan_init(pwm_channel_t const n, clk_src_t const clk_src,uint8 const align, uint8 const polarity)


}

void ocr_rgb_led_off(oct_rgb_led_t p_led)
{

}

void oct_rgb_led_on(oct_rgb_led_t p_led)
{

}

void oct_rgb_led_set_color(oct_rgb_led_t p_led, oct_rgb_led_t p_color)
{

}

void oct_rgb_led_toggle(oct_rgb_led_t p_led)
{

}

static void oct_rgb_led_callback()
{

}

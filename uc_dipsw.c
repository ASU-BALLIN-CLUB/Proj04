//
//  uc_dipsw.c
//
//	Proj02
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

#include "uc_dipsw.h"

// Gives the state of the dipswitch.
uc_dipsw_state_t uc_dipsw_get_state(uc_dipsw_t p_switch)
{
	 uc_dipsw_state_t state = (uc_dipsw_state_t)gpio_port_get_pin_state(gpio_port_dd, (gpio_pin_t)p_switch);
	 return state;
}

// Initializes all of the dipswitches.
void uc_dipsw_init()
{
	gpio_port_init(gpio_port_dd , gpio_pin_4, gpio_funct_gpio, gpio_data_dir_in, gpio_pin_state_low);
	gpio_port_init(gpio_port_dd , gpio_pin_5, gpio_funct_gpio, gpio_data_dir_in, gpio_pin_state_low);
	gpio_port_init(gpio_port_dd , gpio_pin_6, gpio_funct_gpio, gpio_data_dir_in, gpio_pin_state_low);
	gpio_port_init(gpio_port_dd , gpio_pin_7, gpio_funct_gpio, gpio_data_dir_in, gpio_pin_state_low);
}

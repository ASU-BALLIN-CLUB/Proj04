//
//  oct_rgb_led.h
//
//	Proj02
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

#ifndef ____oct_rgb_led__
#define ____oct_rgb_led__

#include "support_common.h"
#include"gpio.h"
#include"global.h"
#include"int.h"
#include"uc_dipsw.h"
#include"gpt.h"
#include"oct_rgb_led.h"
#include"pit.h"
#include"pwm.h"
#include"uc_pushb.h"

typedef enum {
 LED1_COM = 4, // Pin 4 of a GPIO port
 LED2_COM = 6, // Pin 6 of a GPIO port
 LED3_COM = 7, // Pin 7 of a GPIO port
} oct_rbg_pin_t;

typedef enum {
 LED1_COM1 = 0, // Pin 4 of a GPIO port
 LED2_COM1 = 1, // Pin 6 of a GPIO port
 LED3_COM1 = 2, // Pin 7 of a GPIO port
} oct_rgb_led_t;

typedef enum {
 false = 0;
 true = 1;
} bool_t;

#endif

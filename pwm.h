//
//  pwm.h
//
//	Proj02
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

#ifndef ____pwm__
#define ____pwm__


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
 clk_src_a  = 0, //
 clk_src_sa = 1, //
 clk_src_b  = 2, //
 clk_src_sb = 3
} clk_src_t;

typedef enum {
 period_200 = 200, // Pin 4 of a GPIO port
 period_150 = 150, // Pin 6 of a GPIO port
 period_100 = 100,
 period_202 = 202
 // Pin 7 of a GPIO port
} period_t;

typedef enum {
 pwm_channel_1  = 0, //
 pwm_channel_2  = 1, //
 pwm_channel_3  = 2, //
 pwm_channel_4  = 3, //
 pwm_channel_5  = 4, //
 pwm_channel_6  = 5, //
 pwm_channel_7  = 6, //
 pwm_channel_8  = 7 //
} pwm_channel_t;

typedef enum {
 high_polarity = 1, //
 low_polarity = 0 //
} pwm_polarity_t;

typedef enum {
 left_aligned  = 0, //
 center_aligned = 1 //
} pwm_aligned_t;

void pwm_clk_config(clk_src_t const clk_src, uint8 const p_prescale, uint8 const p_scale);
void pwm_chan_init(pwm_channel_t const n, clk_src_t const clk, pwm_aligned_t const align, pwm_polarity_t const polarity);
void pwm_chan_start(pwm_channel_t const n, uint8 const period, uint8 const duty);
void pwm_chan_stop(pwm_channel_t const n);

#endif

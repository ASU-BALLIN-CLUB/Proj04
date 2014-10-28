//
//  pwm.h
//
//	Proj02
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

typedef enum {
 clk_src_a  = 0, //
 clk_src_sa = 1, //
 clk_src_b  = 2, //
 clk_src_sb = 3
} clk_src_t;

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

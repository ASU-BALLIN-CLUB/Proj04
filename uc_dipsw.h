//
//  uc_dipsw.h
//
//	Proj02
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

#ifndef ____uc_dipsw__
#define ____uc_dipsw__
#include "support_common.h"
#include "gpio.h"


typedef enum {
 uc_dipsw_1 = 4, // Represents subswitch 1
 uc_dipsw_2 = 5, // Represents subswitch 2
 uc_dipsw_3 = 6, // Represents subswitch 3
 uc_dipsw_4 = 7 // Represents subswitch 4
} uc_dipsw_t;
typedef enum {
 uc_dipsw_state_off = 1, // Represents the Off state
 uc_dipsw_state_on = 0 // Represents the On state
} uc_dipsw_state_t;

uc_dipsw_state_t uc_dipsw_get_state(uc_dipsw_t p_switch);
void uc_dipsw_init();

#endif /* defined (__uc_dipsw__) */

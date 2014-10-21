//
//  pwm.c
//
//	Proj02
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

static uint32 const MCF_PWM_BASE = 0x401B0000;

#define MCF_PWM_PWME    	*((volatile uint8 *) (MCF_PWM_BASE + 0x00)
#define MCF_PWM_PWMPOL  	*((volatile uint8 *) (MCF_PWM_BASE + 0x01)
#define MCF_PWM_PWMCLK  	*((volatile uint8 *) (MCF_PWM_BASE + 0x02)
#define MCF_PWM_PWMPRCLK 	*((volatile uint8 *) (MCF_PWM_BASE + 0x03)
#define MCF_PWM_PWMCAE   	*((volatile uint8 *) (MCF_PWM_BASE + 0x04)
#define MCF_PWM_PWMCTL   	*((volatile uint8 *) (MCF_PWM_BASE + 0x05)
#define MCF_PWM_PWMSCLA  	*((volatile uint8 *) (MCF_PWM_BASE + 0x08)
#define MCF_PWM_PWMSCLB  	*((volatile uint8 *) (MCF_PWM_BASE + 0x09)
#define MCF_PWM_PWMCNT(n)   *((volatile uint8 *) (MCF_PWM_BASE + 0x0C + (n))
#define MCF_PWM_PWMPER(n)   *((volatile uint8 *) (MCF_PWM_BASE + 0x14 + (n))
#define MCF_PWM_PWMDTY(n)   *((volatile uint8 *) (MCF_PWM_BASE + 0x1C + (n))
#define MCF_PWM_PWMSDN   	*((volatile uint8 *) (MCF_PWM_BASE + 0x24)
#define MCF_PWM_PCME     	*((volatile uint8 *) (MCF_PWM_BASE + 0x26)



void pwm_clk_config(clk_src, prescale, scale)
{
	MCF_PWM_PWMPOL = 0b11111111;

}

void pwm_chan_init(channel n, clk_src, align, polarity)
{

}

void pwm_chan_start(channel n, period, duty)
{

}

void pwm_chan_stop(channel n)
{

}


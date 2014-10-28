//
//  pit.c
//
//	Proj02
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

#include "pit.h"

static uint32 const MCF_PIT_BASE = 0x40150000;


#define MCF_PIT_PCSR(timer)  *((volatile uint16 *) (MCF_PIT_BASE + 0x00 + ((timer) << 4))
#define MCF_PIT_PMR(timer)   *((volatile uint16 *) (MCF_PIT_BASE + 0x02 + ((timer) << 4))
#define MCF_PIT_PCNTR(timer) *((volatile uint16 *) (MCF_PIT_BASE + 0x04 + ((timer) << 4))

void pit_init(pit_timer_t const n, uint8 const p_prescaler, uint16 const p_pmr ,int_isr_t const p_callback)
{
	pit_disable(n);
	MCF_PIT_PCSR(n) &= 0x0000;
	MCF_PIT_PCSR(n) |= (p_prescaler << 8);
	MCF_PIT_PCSR(n) |= 0x003E;
	MCF_PIT_PMR(n) &= 0x0;
	MCF_PIT_PMR(n) |= p_pmr;
	int_config(PIT_INT_SRC(n), PIT_INT_LVL(n), PIT_INT_PRI(n), g_pit_isrs[n]);
	g_pit_callbacks[n] = p_callback;
}

void pit_disable(pit_timer_t const n)
{
	MCF_PIT_PCSR(n) &= 0xFFFE;
}

void pit_enable(pit_timer_t const n)
{
	MCF_PIT_PCSR(n) |= 0x0001;
}

__declspec(interrupt) void pit0_isr()
{
	MCF_PIT_PCSR(0) |= (0x04);
	if(g_pit_callbacks[0] != 0)
	{
		(*g_pit_callbacks[0])();
	}
}

__declspec(interrupt) void pit1_isr()
{
	MCF_PIT_PCSR(1) |= (0x04);
	if(g_pit_callbacks[1] != 0)
	{
		(*g_pit_callbacks[1])();
	}
}

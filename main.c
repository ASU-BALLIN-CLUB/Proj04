//
//  main.c
//
//	Proj04
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//




static void hw_init()
{
	int_inhibit_all();
	oct_rgb_led_init();
	uc_pushb_init(uc_pushb_1, pushb_1_callback);
	int_uninhibit_all();
}

static void pushb_1_callback()
{

}

static void run()
{

}

__declspec(noreturn) int main()
{
	hw_init();
	run();
}

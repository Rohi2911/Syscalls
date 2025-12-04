#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched/clock.h>

SYSCALL_DEFINE0(get_current_time) 
{
	unsigned long long a = sched_clock();
	
	printk(" current time is %llu\n", a);
	return a;
}

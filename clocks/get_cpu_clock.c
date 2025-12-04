#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched/clock.h>

SYSCALL_DEFINE1(get_cpu_clock, int, cpu)
{
	u64 a = cpu_clock(cpu);
	printk("current cpu_clock time is %llu", a);
	return a;
}

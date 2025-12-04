#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched/clock.h>

SYSCALL_DEFINE0(get_local_clock)
{
	u64 a = local_clock();
	printk("current local_clock time is %llu", a);
	return a;
}

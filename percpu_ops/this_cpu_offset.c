#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <asm/smp.h>
#include <linux/smp.h>

SYSCALL_DEFINE2(this_cpu_offset, int *, a, int *, b)
{
	*a = raw_smp_processor_id();
	*b = get_cpu();
	printk("System call returns this cpu\n");
	return 0;
}

/*
 *  This program writes a 64-bit value to a msr register.
 *  @msr_no is msr register number which is being written.
 *  @cpu is the cpu number, on that msr register the operation is performed.
 *  @l is the variable holding data which will be written to lower 32-bit of msr register.
 *  @h is the variable holding data which will be written to higher 32-bit of msr register.
 */

#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <asm/msr.h>
#include <asm-generic/int-ll64.h>

SYSCALL_DEFINE4(write_on_msr, unsigned int, cpu, u32, msr_no, u32, l, u32, h)
{

	wrmsr_on_cpu(cpu, msr_no, l, h);
	printk("Vale successfully written on msr ");
	return 0;
}

/*
 *  This program reads 64-bit value from an msr register.
 *  @msr_no is the msr number of the register which value we want to read.
 *  @cpu is cpu number which msr we want to access.
 *  @l points to where lower 32-bit of msr register value is stored.
 *  @h points to where higher 32-bit of msr register value is stored.
 */


#include <linux/kernel.h>
#include <linux/syscalls.h>
//#include <asm/msr.h>
#include <asm-generic/int-ll64.h>

SYSCALL_DEFINE4(read_on_msr, unsigned int, cpu, u32, msr_no, u32 *, l, u32 *, h)
{
	int a = rdmsr_on_cpu(cpu, msr_no, l, h);
	printk("System call read msr successfully");
	return a;
}

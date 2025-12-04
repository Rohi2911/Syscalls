#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <asm/apicdef.h>
#include <asm/cpufeatures.h>
#include <asm/apic.h>

#define APIC_DIVISOR 16

SYSCALL_DEFINE3(set_lapic, unsigned int, clocks, int, oneshot, int, irqen)
{
	unsigned int lvtt_val, tmp_val;
	lvtt_val = 0xec;
	if (!oneshot)
		lvtt_val |= APIC_LVT_TIMER_PERIODIC;
	else if (boot_cpu_has(X86_FEATURE_TSC_DEADLINE_TIMER))
		lvtt_val |= APIC_LVT_TIMER_TSCDEADLINE;
		

	if (!irqen)
		lvtt_val |= APIC_LVT_MASKED;

	apic_write(APIC_LVTT, lvtt_val);

	if (lvtt_val & APIC_LVT_TIMER_TSCDEADLINE) {
		/*
		 * See Intel SDM: TSC-Deadline Mode chapter. In xAPIC mode,
		 * writing to the APIC LVTT and TSC_DEADLINE MSR isn't serialized.
		 * According to Intel, MFENCE can do the serialization here.
		 */
		asm volatile("mfence" : : : "memory");
		return -1;
		}
		
		tmp_val = apic_read(APIC_TDCR);
	apic_write(APIC_TDCR,
		(tmp_val & ~(APIC_TDR_DIV_1 | APIC_TDR_DIV_TMBASE)) |
		APIC_TDR_DIV_16);

	if (!oneshot)
		apic_write(APIC_TMICT, clocks / APIC_DIVISOR);
	printk("System call successful");
	
	return 0;

}

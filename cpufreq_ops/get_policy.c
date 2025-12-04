#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/cpufreq.h>

SYSCALL_DEFINE1(get_policy, unsigned int, cpu)
{
	struct cpufreq_policy *a = cpufreq_cpu_get(cpu);
	struct cpufreq_governor *b = a->governor;
	char *name = b->name;
	printk("%s\n", name);
	return 0;
}

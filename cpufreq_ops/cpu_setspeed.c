#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/cpufreq.h>

SYSCALL_DEFINE2(cpu_setspeed, unsigned int, cpu, unsigned int, freq)
{
	struct cpufreq_policy *policy = cpufreq_cpu_get(cpu);
	struct cpufreq_governor *gnr = policy->governor;
	gnr->store_setspeed(policy, freq);
	cpufreq_cpu_put(policy);
	
	printk("System call runs successfully\n");
	return 0;
}

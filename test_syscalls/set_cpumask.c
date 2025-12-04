#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/cpumask.h>
#include <linux/bitops.h>
#include <linux/types.h>
#include <linux/uaccess.h>
#include <linux/compiler_types.h>

#define rt_server_cpumask 0x4;

SYSCALL_DEFINE0(set_cpumask)
{
	struct task_struct *p = current;
	pid_t pid = p->pid;
	cpumask_var_t new_mask;
	int retval;

	if (!alloc_cpumask_var(&new_mask, GFP_KERNEL))
		return -ENOMEM;
		
	unsigned len = cpumask_size();
	unsigned long mask = rt_server_cpumask;
	unsigned long __user *user_mask_ptr = &mask;
	
	retval = copy_from_user(new_mask, user_mask_ptr, len)? -EFAULT : 0;
	
	//if(retval == 0)
		retval = sched_setaffinity(pid, new_mask);
	free_cpumask_var(new_mask);
	return retval;
}

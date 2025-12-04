#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/hrtimer.h>
#include <linux/string.h>
#include <linux/ktime.h>
//#include <linux/container_of.h>

struct list {
	struct hrtimer timer;
	int index;
	int count;
};

static enum hrtimer_restart list_timer_callback(struct hrtimer *time) 
{
	struct list *p = container_of(time, struct list, timer);
	printk("DONE");
	return HRTIMER_NORESTART;
}

SYSCALL_DEFINE0(hrtimer)
{
	struct list *list1;
	memset(list1, 0, sizeof(*list1));
	hrtimer_init(&list1->timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	ktime_t t = ktime_set(1000, 1000);
	list1->timer.function = &list_timer_callback;
	//list1->timer._softexpires = t;
	hrtimer_start(&list1->timer, t, HRTIMER_MODE_REL);
	return 0;
}

#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/types.h>
#include <linux/slab.h>
//#include <linux/container_of.h>

struct fox {

	int index;
	struct list_head list;
};

SYSCALL_DEFINE0(opr_on_llist) {
	
	struct fox *red_fox;
	red_fox = kmalloc(sizeof(*red_fox), GFP_KERNEL);
	red_fox->index = 1;
	INIT_LIST_HEAD(&red_fox->list);
	
	struct fox *black_fox;
	black_fox = kmalloc(sizeof(*black_fox), GFP_KERNEL);
	black_fox->index = 2;
	INIT_LIST_HEAD(&black_fox->list);
	
	red_fox->list.next = &(black_fox->list);
	printk("%lu\n", red_fox->index);
	
	int a = container_of(red_fox->list.next, struct fox, list)->index;
	printk("%lu\n", a);
	
	return 0;
	
}

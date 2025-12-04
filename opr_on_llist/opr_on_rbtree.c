#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/rbtree.h>
#include <linux/slab.h>
#include <linux/types.h>

struct grq {
	struct rb_node node;
	int priority;
};

int insert(struct rb_root *root, struct grq *node)
{
	struct rb_node **new = &(root->rb_node), *parent = NULL;
	
	while(*new) {
		struct grq *this = container_of(*new, struct grq, node);
		parent = *new;
		
		if(node->priority < this->priority) 
			new = &((*new)->rb_left);
		else
			new = &((*new)->rb_right);
		
		}
	rb_link_node(&node->node, parent, new);
	rb_insert_color(&node->node, root);
	return 0;
	
}

SYSCALL_DEFINE0(opr_on_rbtree)
{
	struct rb_root grq_root = RB_ROOT;
	struct grq *p = kmalloc(sizeof(*p), GFP_KERNEL);
	p->priority = 5;
	insert(&grq_root, p);
	printk("Value inserted");
	return 0;
	
}

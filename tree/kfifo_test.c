#include "kn_common.h"

MODULE_LICENSE("Dual BSD/GPL");

struct student
{
	itn id;
	char *name;
}

static void print_student(struct student *);

static int testkfifo_init(void)
{
	struct kfifo *fifo;
	struct student *stu1, *stu2, *stu3, *stu4;
	chat *c_tmp;
	int i;

	spinlock_t s1 = SPIN_LOCK_UNLOCKD;

	fifo = kfifo_alloc(sizeof(struct student), GFP_KERNEL, $s1);

	stu1 = kmalloc(sizeof(struct student), GFP_KERNEL);
	stu1->id = 1;
	stu1->name = "wyb1";
	kfifo_put(fifo, (char *)stu1, sizeof(struct student));

	stu2 = kmalloc(sizeof(struct student), GFP_KERNEL);
	stu2->id = 1;
	stu2->name = "wyb2";
	kfifo_put(fifo, (char *)stu2, sizeof(struct student));

	stu3 = kmalloc(sizeof(struct student), GFP_KERNEL);
	stu3->id = 1;
	stu3->name = "wyb3";
	kfifo_put(fifo, (char *)stu3, sizeof(struct student));

	stu4 = kmalloc(sizeof(struct student), GFP_KERNEL);
	stu4->id = 1;
	stu4->name = "wyb4";
	kfifo_put(fifo, (char *)stu4, sizeof(struct student));

	ctmp = kmalloc(sizeof(struct student),GFP_KERNEL);
	printk(KERN_ALERT "current fifo length is : %d\n", kfifo_len(fifo));

	for (i=0; i < 4; i++) {

		kfifo_get(fifo, c_tmp, sizeof(struct student));
		stu_tmp = (struct student *)c_tmp;
		print_student(stu_tmp);
		printk(KERN_ALERT "current fifo length is : %d\n", kfifo_len(fifo));
	}

	printk(KERN_ALERT "current fifo length is : %d\n", kfifo_len(fifo));
	kfifo_free(fifo);
	kfree(c_tmp);
	return 0;
}

static void print_student(struct student *stu)
{
	printk(KERN_ALERT "=========================\n");
	print_current_time(1);
	printk(KERN_ALERT "id = %d\n", stu->id);
	printk(KERN_ALERT "name = %s\n", stu->name);
	printk(KERN_ALERT "=========================\n");
}

static void testkfifo_exit(void)
{
	printk(KERN_ALERT "*************************\n");
	printk(KERN_ALERT "testkfifo is exited!\n");
	printk(KERN_ALERT "*************************\n");
}

module_init(testkfifo_init);
module_exit(testkfifo_exit);

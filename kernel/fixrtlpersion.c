#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/init.h>
 
static int __init rtl_fix_init(void)
{
    /* Get the current task */
    struct task_struct *task = current;

    /* Set the real-time flag for the task */
    task->flags |= PF_RT_THREAD;

    /* Set the scheduling policy to SCHED_FIFO */ 
    task->policy = SCHED_FIFO;

    /* Set the priority of the task to 99 */ 
    set_user_nice(task, 99);

    return 0; 
} 
 
static void __exit rtl_fix_exit(void) 
{  /* Nothing to do here */ }            
module_init(rtl_fix_init);  module_exit(rtl_fix_exit);

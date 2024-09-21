#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/ktime.h>
#include <linux/delay.h>

MODULE_AUTHOR("Gertjan Hofman (gertjan.hofman@honeywell.com");
MODULE_DESCRIPTION("Kernel Sleep test");
MODULE_LICENSE("GPL")
MODULE_VERSION("0.0.1")

#define START_SLEEP_NS 1000
#define END_SLEEP_NS 100000
#define SLEEP_STEPS 20

static int __init sleep_test_init(void) {
    int i;
    ktime_t start_time, end_time;
    s64 actual_sleep_time_ns;
    u32 actual_sleep_time_us;

    pr_info("Sleep test module loaded\n");

    for (i = 0; i <= SLEEP_STEPS; i++) {
        u32 sleep_time_ns = START_SLEEP_NS + i * (END_SLEEP_NS - START_SLEEP_NS) / SLEEP_STEPS;
        u32 min_sleep_us  = sleep_time_ns / 1000;
        u32 max_sleep_us  = (sleep_time_ns + 1000) / 1000; // Ensure at least 1 us range

        start_time = ktime_get_real();
        usleep_range(min_sleep_us, max_sleep_us);
        //udelay(min_sleep_us);
        end_time = ktime_get_real();

        actual_sleep_time_ns = ktime_to_ns(ktime_sub(end_time, start_time));

        actual_sleep_time_us = (u32) actual_sleep_time_ns /1000;

        pr_info("Requested sleep: %u us: %u us, Actual sleep: %u us %lld\n", min_sleep_us, max_sleep_us, actual_sleep_time_us, actual_sleep_time_ns);
    }

    return 0;
}

static void __exit sleep_test_exit(void)
{
	pr_info("module unloaded.\n")
}

module_init(sleep_test_init);
module_exit(sleep_test_exit);


#include <rtthread.h>

int hello_func(void)
{
    rt_kprintf("Hello RT-Thread!\n");
    return 0;
}

int hello_init(void)
{
    rt_kprintf("hello package initialized.\n");

    return 0;
}
INIT_APP_EXPORT(hello_init);

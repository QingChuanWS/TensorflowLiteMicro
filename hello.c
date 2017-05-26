#include <rtthread.h>
#include <finsh.h>

int hello_func(int argc, char** argv)
{
    rt_kprintf("Hello RT-Thread!\n");
    return 0;
}
MSH_CMD_EXPORT(hello_func, say hello);

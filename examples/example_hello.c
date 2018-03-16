#include <rtthread.h>
#include <finsh.h>

#include <hello.h>

int hello_test(int argc, char** argv)
{
    hello_func();

    return 0;
}
MSH_CMD_EXPORT(hello_test, hello API test);

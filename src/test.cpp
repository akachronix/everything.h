#include "brisk.h"

int main(void)
{
    brisk::logger console(brisk::loglevel::everything, "console.log");
    console << "hello, world!" << brisk::newl;

    return 0;
}
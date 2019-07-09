#include "brisk/brisk.h"

int main(void)
{
    brisk::logger cout(brisk::loglevel::everything, "cout.log");
    cout << "hello, world\n";
}


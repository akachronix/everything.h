#include "brisk.h"

int main(void)
{
    brisk::logger cout(brisk::loglevel::everything, "cout.log");
    cout << "Hello, world!" << brisk::newl;

    return 0;
}

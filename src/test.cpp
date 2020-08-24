#include "brisk/logger.hpp"
#include "brisk/string.hpp"
#include "brisk/memory.hpp"

int main(void)
{
    brisk::logger cout(brisk::loglevel::everything, "cout.log");
    cout.disablePrinting();

    brisk::unique_ptr<brisk::string*> ptr(new brisk::string);
    ptr->append("hello, world");
    ptr->append("hello from brisk!");

    cout << *ptr;
}
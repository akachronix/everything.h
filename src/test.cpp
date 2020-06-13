#include "brisk/logger.hpp"
#include "brisk/string.hpp"

void string_info(brisk::logger& cout, brisk::string& s)
{
    cout << "s.size() = " << s.size() << '\n';
    cout << "s.capacity() = " << s.capacity() << '\n';
    for (size_t i = 0; i < s.capacity(); ++i) {
        if (i < s.size())
            cout << "s[" << i << "] = " << (char)s.data()[i] << '\n';
        else
            cout << "s[" << i << "] = " << (int)s.data()[i] << '\n';
    }
}

int main(void)
{
    brisk::logger cout(brisk::loglevel::everything, "cout.log");
    
    brisk::string s = "hello, world! :)";
    string_info(cout, s);

    brisk::string s2;
    string_info(cout, s2);

    cout << s << brisk::newl;
    cout.shrink_to_fit();
}
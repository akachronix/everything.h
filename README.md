# everything.h
Compiles on Linux & Mac (using Make) and Windows (using MinGW).

## Usage
First, refer to the Build section for your platform. So, now, you officially have set it up I'll assume.

All the libraries are split up into their respective headers. The libraries in ```everything.h``` are:
- libinput, a pretty crappy wrapper around std::cin
- libpair, a pretty crappy recreation of std::pair
- libcalc, a pretty crappy template class for calculating stuff
- libmath, a pretty crappy math header
- liblog, a pretty good wrapper around std::cin and std::cout that will dump everything output to the console to a log file automagically for you
- libptr, a pretty crappy scoped pointer

Including ```everything.h``` will, for namesakes, include all of these. However, just append ```.hpp``` to the library name to just get the library you want.

## Reference
### libinput
#### Functions
- ```int GetInt(std::string prompt)```
- ```long int GetLongInt(std::string prompt)```
- ```long long int GetLongLongInt(std::string prompt)```
- ```float GetFloat(std::string prompt)```
- ```double GetDouble(std::string prompt)```
- ```long double GetLongDouble(std::string prompt)```
- ```std::string GetString(std::string prompt)```

### liblog
#### Enum Classes
- ```loglevel_t```

#### Classes
- Logger (typedefed to ```logger_t```)
  - ```Logger()```
  - ```~Logger()```
  - ```Logger(loglevel_t _loglevel, std::string _logfile)```
  - ```void disableLogging()```
  - ```void enableLogging(loglevel_t _loglevel)```
  - ```std::vector<std::string> getLog()```
  - ```bool logError(std::string error_str)```
  - ```bool logWarning(std::string warning_str)```
  - ```bool print(short value);```
  - ```bool print(unsigned short value);```
  - ```bool print(int value);```
  - ```bool print(unsigned int value);```
  - ```bool print(float value);```
  - ```bool print(double value);```
  - ```bool print(long double value);```
  - ```bool print(const char* print_str);```
  - ```bool print(std::string print_str);```
  - ```bool print(Logger&(*func)(Logger&));```
  - ```void input(short& var);```
  - ```void input(unsigned short& var);```
  - ```void input(int& var);```
  - ```void input(unsigned int& var);```
  - ```void input(float& var);```
  - ```void input(double& var);```
  - ```void input(long double& var);```
  - ```void input(const char* var);```
  - ```void input(std::string& var);```
  - ```bool dumpLog(std::string file);```
  - ```bool dumpLog();```

#### Functions


## Background
```everything.h``` is a header-only library that I've written myself for myself. However, I do believe in free software so I have open-sourced it onto here to hopefully get some suggestions. All this started for CCalc, my calculator program that I wrote for myself to use in school to make my life easier when answering math questions.

## Requirements
### Linux
- GCC 4.8.1
- git
- make (only if compiling test program)

### Windows
- Cygwin or MinGW (in PATH)
- Git
- GCC 4.8.1 (if using Cygwin)

## Build (Linux)
- Install the ```git``` package.
- Clone repository using ```git clone https://github.com/akachronix/everything.h.git```
- Copy headers to whereever, and then set your path using the ```-I``` compiler argument.
- Success.

## Build (Windows)
- Install Git for Windows.
- Clone repository using ```git clone https://github.com/akachronix/everything.h.git```
- Open a Command Prompt where Git for Windows cloned the repository.
- Copy headers to whereever, and then set your path using the ```-I``` compiler argument.
- Success.

## Help
If you think you've found a bug, leave an issue. If you have some changes to suggest, make a pull request or put ```[REQUEST]``` before an issue.

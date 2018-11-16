# brisk
Compiles on Linux & Mac (using Make) and Windows (using MinGW).

## Background
```brisk``` is a header-only library that I've written myself for myself. However, I do believe in free software so I have open-sourced it onto here to hopefully get some suggestions. All this started for CCalc, my calculator program that I wrote for myself to use in school to make my life easier when answering math questions.

## Usage
First, refer to the Build section for your platform. So, now, you officially have set it up I'll assume.

All the libraries are split up into their respective headers. The libraries in ```brisk``` are:
- algorithm, a WIP library including copy functions for ```array``` and ```vector```
- array, a replacement for std::array
- logger, a pretty good wrapper around std::cin and std::cout that will dump everything output to the console to a log file automagically for you
- math, containers for geometric shapes
- pair, a replacement for std::pair
- vector, a replacement for std::vector

Including ```brisk.h``` will, for namesakes, include all of these. However, just append ```.hpp``` to the library name to just get the library you want.

## Reference
### algorithm
#### Functions
- ```template<typename T> vector<T> copy(vector<T>& v)```
- ```template<typename T, size_t _Size> vector<T> copy(array<T, _Size>& a)```
- ```template<typename T> void copy(vector<T>& v, vector<T>& v2)```
- ```template<typename T, size_t _Size> void copy(array<T, _Size>& a, vector<T>& v)```

### array
#### Classes
- array
  - ```array()```
  - ```array(const std::initializer_list<T> list)```
  - ```~array()```
  - ```array(array&) = delete```
  - ```array(array&&) = delete```
  - ```T& operator[](const size_t index) noexcept```
  - ```const T& operator[](const size_t index) const noexcept```
  - ```T& at(const size_t index)```
  - ```const T& at(const size_t index) const```
  - ```T* data() noexcept```
  - ```size_t size() const noexcept```
  - ```bool empty() const noexcept```
  - ```T* begin() noexcept```
  - ```T* end() noexcept```
  - ```const T* cbegin() const noexcept```
  - ```const T* cend() const noexcept```
  - ```std::reverse_iterator<T*> rbegin() noexcept```
  - ```std::reverse_iterator<T*> rend() noexcept```
  - ```std::reverse_iterator<const T*> crbegin() const noexcept```
  - ```std::reverse_iterator<const T*> crend() const noexcept```

### logger
#### Enum Classes
- ```loglevel_t```

#### Classes
- logger (typedefed to ```logger_t```)
  - ```logger()```
  - ```~logger()```
  - ```logger(loglevel_t _loglevel, std::string _logfile)```
  - ```bool logError(std::string error_str)```
  - ```bool logWarning(std::string warning_str)```
  - ```template<typename T> bool print(T value)```
  - ```template<typename T> void input(T& var)```
  - ```bool print(logger& (*func)(Logger&))```
  - ```bool dumpLog(std::string file);```
  - ```bool dumpLog();```

#### Functions
- Output Operators
  - ```template<typename T> logger& operator<<(logger& log, T value)```
  - ```logger& operator<<(logger& log, logger& (*func)(logger&))```
  
- Input Operators
  - ```template<typename T> logger& operator>>(logger& log, T& value)```

- Stream Manipulators
  - ```Logger& newl(Logger& log)```
  - ```Logger& stab(Logger& log)```
  - ```Logger& tab(Logger& log)```
  - ```Logger& space(Logger& log)```

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
- Clone repository using ```git clone https://github.com/akachronix/brisk.git```
- Copy headers to whereever, and then set your path using the ```-I``` compiler argument.
- Success.

## Build (Windows)
- Install Git for Windows.
- Clone repository using ```git clone https://github.com/akachronix/brisk.git```
- Open a Command Prompt where Git for Windows cloned the repository.
- Copy headers to whereever, and then set your path using the ```-I``` compiler argument.
- Success.

## Help
If you think you've found a bug, leave an issue. If you have some changes to suggest, make a pull request or put ```[REQUEST]``` before an issue.

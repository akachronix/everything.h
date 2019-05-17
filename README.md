# brisk
Compiles on Linux & Mac (using Make) and Windows (using MinGW).

## Background
```brisk``` is a header-only library that I've written myself for myself. However, I do believe in free software so I have open-sourced it onto here to hopefully get some suggestions. All this started for CCalc, my calculator program that I wrote for myself to use in school to make my life easier when answering math questions.

## Usage
First, refer to the Build section for your platform. So, now, you officially have set it up I'll assume.

All the libraries are split up into their respective headers. The libraries in ```brisk``` are:
  - ```algorithm```, a WIP library including copy functions for ```array``` and ```vector```
  - ```array```, a replacement for ```std::array```
  - ```functional```, a replacement for the ```functional``` header
  - ```logger```, a pretty good wrapper around ```std::cin``` and ```std::cout``` that will dump everything output to the console to a log file automagically for you
  - ```math```, containers for geometric shapes
  - ```memory```, smart pointer stuff
  - ```string```, a replacement for ```std::string```
  - ```utility```, a replacement for the ```utility``` header
  - ```vector```, a replacement for ```std::vector```

Including ```brisk.h``` will, for namesakes, include all of these. However, just append ```.hpp``` to the library name to just get the library you want.

## Reference (last updated May 16th, 2019)
### algorithm
#### Functions
  - ```template<class Iterator, class T> constexpr void fill(Iterator first, Iterator last, const T&& value)```
  - ```template<class Iterator, class Function, class... Args> Function for_each(Iterator first, Iterator last, Function f, Args... args)```
  - ```template<class Iterator, class Function> Function for_each(Iterator first, Iterator last, Function f)```
  - ```template<class T> vector<T> copy(vector<T>& v)```
  - ```template<class T, size_t _Size> vector<T> copy(array<T, _Size>& a)```
  - ```template<class T> void copy(vector<T>& v, vector<T>& v2)```
  - ```template<class T, size_t _Size> void copy(array<T, _Size>& a, vector<T>& v)```
  - ```template<class Container> auto begin(Container& c) -> decltype(c.begin())```
  - ```template<class Container> auto end(Container& c) -> decltype(c.end())```
  - ```template<class Container> auto cbegin(Container& c) -> decltype(c.cbegin())```
  - ```template<class Container> auto cend(Container& c) -> decltype(c.cend())```
  - ```template<class Container> auto rbegin(Container& c) -> decltype(c.rbegin())```
  - ```template<class Container> auto rend(Container& c) -> decltype(c.rend())```
  - ```template<class Container> auto crbegin(Container& c) -> decltype(c.crbegin())```
  - ```template<class Container> auto crend(Container& c) -> decltype(c.crend())```

### array
#### Typedefs
  - ```size_type = size_t```
  - ```value_type = Type```
  - ```pointer = Type*```
  - ```const_pointer = const Type*```
  - ```reference = Type&```
  - ```const_reference = const Type&```
  - ```iterator = Type*```
  - ```const_iterator = const Type*```
  - ```reverse_iterator = std::reverse_iterator<iterator>```
  - ```const_reverse_iterator = std::reverse_iterator<const_iterator>```
  - ```difference_type = ptrdiff_t```

#### Classes
- ```template<typename Type, size_t Size> array```
  - ```array(array&) = delete```
  - ```array(array&&) = delete```
  - ```array() = default```
  - ```~array() = default```
  - ```array(const std::initializer_list<T> list)```
  - ```reference operator[](const size_type index) noexcept```
  - ```const_reference operator[](const size_type index) const noexcept```
  - ```reference at(const size_type index)```
  - ```const_reference at(const size_type index) const```
  - ```reference front() noexcept```
  - ```const_reference front() const noexcept```
  - ```reference back() noexcept```
  - ```const_reference back() const noexcept```
  - ```pointer data() noexcept```
  - ```constexpr size_type size() noexcept```
  - ```constexpr size_type max_size() noexcept```
  - ```bool empty() const noexcept```
  - ```void fill(const value_type& value)```
  - ```iterator begin() noexcept```
  - ```iterator end() noexcept```
  - ```const_iterator cbegin() const noexcept```
  - ```const_iterator cend() const noexcept```
  - ```reverse_iterator rbegin() noexcept```
  - ```reverse_iterator rend() noexcept```
  - ```const_reverse_iterator crbegin() const noexcept```
  - ```const_reverse_iterator crend() const noexcept```

### functional
#### Functions
  - ```template<class Function, class... Args> decltype(auto) invoke(Function&& f, Args&&... args) noexcept```

### iterator
#### Typedefs
  - ```pointer = Type*```
  - ```const_pointer = const Type*```
  - ```difference_type = ptrdiff_t```

#### Classes
- ```iterator```
  - ```explicit iterator(const pointer begin, const pointer end)```
  - ```iterator(const iterator& i)```
  - ```iterator(iterator&& i)```
  - ```~iterator()```
  - ```iterator& operator=(const iterator& i)```
  - ```iterator& operator=(iterator&& i)```
  - ```pointer it() noexcept```
  - ```pointer begin() noexcept```
  - ```pointer end() noexcept```
  - ```const_pointer cbegin() const noexcept```
  - ```const_pointer cend() const noexcept```
  - ```difference_type distance() const noexcept```
  - ```difference_type range() const noexcept```
  - ```difference_type pos() const noexcept```
  - ```iterator& operator++() noexcept```
  - ```iterator& operator--() noexcept```
  - ```typename std::add_lvalue_reference<Type>::type operator*() const```

### logger
#### Enum Classes
- ```loglevel_t```
  - ```nothing = -1```
  - ```print = 0```
  - ```errors = 1```
  - ```warnings = 2```
  - ```everything = 3```

#### Classes
- ```logger``` (typedefed to ```logger_t```)
  - ```logger(loglevel_t _loglevel, std::string _logfile)```
  - ```logger(const logger& other)```
  - ```logger(logger&& other)```
  - ```~logger()```
  - ```logger& operator=(const logger& other)```
  - ```logger& operator=(logger&& other)```
  - ```[[nodiscard]] std::string filename() const```
  - ```void filename(const std::string filename) noexcept```
  - ```bool logError(std::string error_str)```
  - ```bool logWarning(std::string warning_str)```
  - ```template<typename T> bool print(T value)```
  - ```template<typename T> void input(T& var)```
  - ```bool print(logger& (*func)(Logger&))```
  - ```[[nodiscard]] std::vector<std::string>& buffer() noexcept```
  - ```[[nodiscard]] const size_t size() const noexcept```
  - ```void shrink_to_fit()```
  - ```bool dumpLog(std::string file) const```
  - ```bool dumpLog() const```
  - ```void disableLogging() noexcept```
  - ```void enableLogging() noexcept```
  - ```void disablePrinting() noexcept```
  - ```void enablePrinting() noexcept```

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

### math
#### Classes
- ```template<class T = long double> struct trapezoid```
  - ```trapezoid() = default```
  - ```trapezoid(T _side1, T _side2, T _height)```
  - ```T area()```

- ```template<class T = long double> struct rectangle```
  - ```rectangle() = default```
  - ```rectangle(T _length, T _width)```
  - ```T area()```

- ```template<class T = long double> struct triangle```
  - ```triangle() = default```
  - ```triangle(T _base, T _height)```
  - ```T area()```

- ```template<class T = long double> struct rhombus```
  - ```rhombus() = default```
  - ```rhombus(T _side)```
  - ```T area()```

- ```template<class T = long double> struct hexagon```
  - ```hexagon() = default```
  - ```hexagon(T _side)```
  - ```T area()```

- ```template<class T = long double> struct circle```
  - ```circle() = default```
  - ```circle(T _radius)```
  - ```T area()```

- ```template<class T = long double> struct square```
  - ```square() = default```
  - ```square(T _side)```
  - ```T area()```

- ```template<class T = long double> struct rectangular_prism```
  - ```rectangular_prism() = default```
  - ```rectangular_prism(T _length, T _width, T _height)```
  - ```T area()```

- ```template<class T = long double> struct triangular_prism```
  - ```triangular_prism() = default```
  - ```triangular_prism(T _length, T _width, T _height)```
  - ```T area()```

- ```template<class T = long double> struct cone```
  - ```cone() = default```
  - ```cone(T _radius, T _height)```
  - ```T area()```

- ```template<class T = long double> struct cube```
  - ```cube() = default```
  - ```cone(T _face)```
  - ```T area()```

### string
#### Classes
- ```class string```
  - ```string()```
  - ```string(const char* s)```
  - ```~string()```
  - ```string& operator=(const string& str)```
  - ```string& operator=(const char* s)```
  - ```string& operator=(char c)```
  - ```char* begin() noexcept```
  - ```char* end() noexcept```
  - ```const char* cbegin() const noexcept```
  - ```const char* cend() const noexcept```
  - ```std::reverse_iterator<char*> rbegin() noexcept```
  - ```std::reverse_iterator<char*> rend() noexcept```
  - ```std::reverse_iterator<const char*> crbegin() const noexcept```
  - ```std::reverse_iterator<const char*> crend() const noexcept```
  - ```size_t size() const noexcept```
  - ```size_t length() const noexcept```
  - ```char& operator[](size_t index)```
  - ```const char& operator[](size_t index) const```
  - ```char& at(size_t index)```
  - ```const char& at(size_t index) const```
  - ```char& front()```
  - ```char& back()```
  - ```const char& front() const```
  - ```const char& back() const```
  - ```char* data() const noexcept```

#### Functions
- ```std::ostream& operator<<(std::ostream& out, const brisk::string& string)```

### utility
#### Functions
- ```template<class T> constexpr T&& forward(typename std::remove_reference<T>::type& t) noexcept```
- ```template<class T> constexpr T&& forward(typename std::remove_reference<T>::type&& t) noexcept```
- ```template<class T> constexpr typename std::remove_reference<T>::type&& move(T&& t) noexcept```
- ```template<class T, class T2> pair<T, T2> make_pair(T x, T2 y)```
- ```template<class T, class T2> constexpr pair<T, T2> make_pair(T&& x, T2&& y)```

#### Classes
- ```template<class T, class T2> struct pair```
  - ```pair() = default```
  - ```pair(T&& x, T2&& y)```

### vector
#### Typedefs
- ```size_type = size_t```
- ```value_type = Type```
- ```pointer = Type*```
- ```const_pointer = const Type*```
- ```reference = Type&```
- ```const_reference = const Type&```
- ```iterator = Type*```
- ```const_iterator = const Type*```
- ```reverse_iterator = std::reverse_iterator<iterator>```
- ```const_reverse_iterator = std::reverse_iterator<const_iterator>```
- ```difference_type = ptrdiff_t```

#### Classes
- ```template<class Type> class vector```
  - ```vector()```
  - ```explicit vector(const size_type size)```
  - ```vector(const std::initializer_list<Type> list)```
  - ```vector(iterator const begin, iterator const end)```
  - ```vector(const vector& v2)```
  - ```vector(vector&& v2)```
  - ```~vector()```
  - ```vector<Type>& operator=(const vector& v2)```
  - ```vector<Type>& operator=(vector&& v2)```
  - ```reference operator[](const size_type index) noexcept```
  - ```const_reference operator[](const size_type index) const noexcept```
  - ```reference at(const size_type index)```
  - ```const_reference at(const size_type index) const```
  - ```reference front() noexcept```
  - ```const_reference front() const noexcept```
  - ```reference back() noexcept```
  - ```const_reference back() const noexcept```	
  - ```pointer data() noexcept```
  - ```const_pointer data() const noexcept```
  - ```template<class... Args> void emplace_back(Args&&... args)```
  - ```void push_back(const std::initalizer_list<Type>&& list)```
  - ```void push_back(const Type& value)```
  - ```void push_back(const Type&& value)```
  - ```void pop_back()```
  - ```size_type capacity() const noexcept```
  - ```size_type size() const noexcept```
  - ```[[nodiscard]] bool empty() const noexcept```
  - ```explicit operator bool() const noexcept```
  - ```void resize(const size_type size)```
  - ```void reserve(const size_type size)```
  - ```void shrink_to_fit()```
  - ```void fill(const value_type& value)```
  - ```bool operator==(const vector<Type>& rhs) const```
  - ```bool operator!=(const vector<Type>& rhs) const```
  - ```iterator begin() noexcept```
  - ```iterator end() noexcept```
  - ```const_iterator cbegin() const noexcept```
  - ```const_iterator cend() const noexcept```
  - ```reverse_iterator rbegin() noexcept```
  - ```reverse_iterator rend() noexcept```
  - ```const_reverse_iterator crbegin() const noexcept```
  - ```const_reverse_iterator crend() const noexcept```

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

# everything.h

**Open-source as in do whatever you want; modify, change, use, use commericially, blah blah blah I don't care.**


**Namespaces:**
* IO
* Math
* PtrMath
* Geometry
* Geometry::Square
* Geometry::Cube
* PtrGeometry
* PtrGeometry::Square
* PtrGeometry::Cube
* RandNum
* Exception


**Features:**
* Written in C++ (well duh)
* Uses C++11
* Organized into namespaces
* Contains error handling enum and functions
* Has a color enum (for some reason)
* Pointer-friendly for the most part
* Nested namespaces for geometry

# Documentation

# IO Functions
Everything.h has many functions for dealing with I/O. Maybe too many. Anyway, instead of listing each one I will give you the prefixes.

*l - long,

*s - signed,

*u - unsigned,

*Int - integer,

*Dbl - double,

*Str - string,

*Lng - long,

*Sht - short,

**Example**

long double example = IO::lDblInput(question);

# Math and PtrMath Functions
This header file also has math functions. I will go ahead and list them.

* Add
* Subtract
* Multiply
* Divide
* SquareRoot
* CubicRoot
* RoundUp
* RoundDown
* Power
* Pi

These are in both Math and the PtrMath namespaces, except for the Pi function.

**Example*

long double answer;

PtrMath::Multiply(&answer, 3, 6);

**OR**

long double answer = Math::Add(50, 50);

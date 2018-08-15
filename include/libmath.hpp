#pragma once

const double pi = 3.141592653;

// 2D shapes
typedef struct {double side1, side2, height, area;} trapezoid_t;
typedef struct {double length, width, area;} rectangle_t;
typedef struct {double base, height, area;} triangle_t;
typedef struct {double side, area;} rhombus_t;
typedef struct {double side, area;} hexagon_t;
typedef struct {double radius, area;} circle_t;
typedef struct {double side, area;} square_t;

// 3D shapes
typedef struct {double length, width, height, area;} rectangular_prism_t;
typedef struct {double length, width, height, area;} triangular_prism_t;
typedef struct {double radius, height, area;} cone_t;
typedef struct {double face, area;} cube_t;

namespace libmath
{
	double add(double x, double y);
	double subtract(double x, double y);
	double multiply(double x, double y);
	double divide(double x, double y);
	double power(double base, double exponent);

	// 2D Shapes
	trapezoid_t Trapezoid(double side1, double side2, double height);
	rectangle_t Rectangle(double length, double height);
	triangle_t Triangle(double base, double height);
	rhombus_t Rhombus(double side);
	hexagon_t Hexagon(double side);
	circle_t Circle(double radius);
	square_t Square(double side);

	// 3D shapes
	rectangular_prism_t Rectangular_Prism(double length, double width, double height);
	triangular_prism_t Triangular_Prism(double length, double width, double height);
	cone_t Cone(double radius, double height);
	cube_t Cube(double face);
}

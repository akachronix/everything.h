#include "brisk/logger.hpp"
#include "brisk/math.hpp"

int main(int argc, const char* argv[])
{
    bool running = true;

    brisk::logger cout(brisk::loglevel::everything, "cout.log");
    cout << "Calc by akachronix (demo of brisk library)\n\n";

    while (running)
    {
        int selection = 0;

        cout << "1) Geometry\n";
        cout << "2) Quit\n\n";
        cout >> selection;

        if (selection == 1)
        {
            cout << "\n1) Trapezoid\n";
            cout << "2) Rectangle\n";
            cout << "3) Triangle\n";
            cout << "4) Rhombus\n";
            cout << "5) Hexagon\n";
            cout << "6) Circle\n";
            cout << "7) Square\n";
            cout << "8) Rectangular Prism\n";
            cout << "9) Triangular Prism\n";
            cout << "10) Cone\n";
            cout << "11) Cube\n";
            cout << "\n";
            cout >> selection;

            switch (selection)
            {
                case 1:
                {
                    long double side1, side2, height;

                    cout << "\nEnter side 1: ";
                    cout >> side1;

                    cout << "Enter side 2: ";
                    cout >> side2;

                    cout << "Enter height: ";
                    cout >> height;

                    brisk::trapezoid<> shape(side1, side2, height);
                    cout << "\nArea: " << shape.area() << "\n\n";
                    
                    break;
                }

                case 2:
                {
                    long double length, width;

                    cout << "\nEnter length: ";
                    cout >> length;

                    cout << "Enter width: ";
                    cout >> width;

                    brisk::rectangle<> shape(length, width);
                    cout << "\nArea: " << shape.area() << "\n\n";

                    break;
                }

                case 3:
                {
                    long double base, height;

                    cout << "\nEnter base: ";
                    cout >> base;

                    cout << "Enter height: ";
                    cout >> height;

                    brisk::triangle<> shape(base, height);
                    cout << "\nArea: " << shape.area() << "\n\n";

                    break;
                }

                case 4:
                {
                    long double side;

                    cout << "\nEnter side: ";
                    cout >> side;

                    brisk::rhombus<> shape(side);
                    cout << "\nArea: " << shape.area() << "\n\n";

                    break;
                }

                case 5:
                {
                    long double side;

                    cout << "\nEnter side: ";
                    cout >> side;

                    brisk::hexagon<> shape(side);
                    cout << "\nArea: " << shape.area() << "\n\n";

                    break;
                }

                case 6:
                {
                    long double radius;

                    cout << "\nEnter radius: ";
                    cout >> radius;

                    brisk::circle<> shape(radius);
                    cout << "\nArea: " << shape.area() << "\n\n";

                    break;
                }

                case 7:
                {
                    long double side;

                    cout << "\nEnter side: ";
                    cout >> side;

                    brisk::square<> shape(side);
                    cout << "\nArea: " << shape.area() << "\n\n";

                    break;
                }

                case 8:
                {
                    long double length, width, height;

                    cout << "\nEnter length: ";
                    cout >> length;

                    cout << "Enter width: ";
                    cout >> width;

                    cout << "Enter height: ";
                    cout >> height;

                    brisk::rectangular_prism<> shape(length, width, height);
                    cout << "\nArea: " << shape.area() << "\n\n";

                    break;
                }

                case 9:
                {
                    long double length, width, height;

                    cout << "\nEnter length: ";
                    cout >> length;

                    cout << "Enter width: ";
                    cout >> width;

                    cout << "Enter height: ";
                    cout >> height;

                    brisk::triangular_prism<> shape(length, width, height);
                    cout << "\nArea: " << shape.area() << "\n\n";

                    break;
                }

                case 10:
                {
                    long double radius, height;

                    cout << "\nEnter radius: ";
                    cout >> radius;

                    cout << "Enter height: ";
                    cout >> height;

                    brisk::cone<> shape(radius, height);
                    cout << "\nArea: " << shape.area() << "\n\n";

                    break;
                }

                case 11:
                {
                    long double face;

                    cout << "\nEnter face: ";
                    cout >> face;

                    brisk::cube<> shape(face);
                    cout << "\nArea: " << shape.area() << "\n\n";

                    break;
                }

                default:
                {
                    cout.logWarning("\nThat is not a valid option!\n");
                    running = false;

                    break;
                }
            }
        }

        else if (selection == 2)
        {
            running = false;
        }

        else
        {
            cout.logWarning("\nThat is not a valid option!\n");
            running = false;
        }
    }

    cout << '\n';
    //cout.shrink_to_fit();
}
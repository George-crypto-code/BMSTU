#include <iostream>
#include <cmath>


bool f(double x, double y, double r)
{
    if (x >= 0 && y >= 0)
        if (std::pow(x, 2) + std::pow(y, 2) <= r * r)
            return true;

    if (x >= 0 && y < 0)
        if (std::pow(x - r, 2) + std::pow(y + r, 2) >= r * r)
            return true;

    if (x < 0 && y < 0)
        if (std::pow(x, 2) + std::pow(y, 2) <= r * r)
            return true;

    if (x < 0 && y >= 0)
        if (std::pow(x + r, 2) + std::pow(y - r, 2) >= r * r)
            return true;

    return false;
}


int main()
{
    double x, y, r;
    std::cout << "Enter radius: ";
    std::cin >> r;
    std::cout << "Enter x of point: ";
    std::cin >> x;
    std::cout << "Enter y of point: ";
    std::cin >> y;

    std::cout << "Point (" << x << "; " << y << ") is " << 
    ((f(x, y, r)) ? "" : "not ") << "belong in our field" << std::endl;
    
    return 0;
}
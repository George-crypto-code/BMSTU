#include <iostream>
#include <cmath>


double f(double x)
{
    if (x <= -2)
        return - 0.5 * x - 1.5;
    if (x >= 2)
        return 0.5 * x - 1.5;
    return 2 * std::cos(2 * x);
}


int main()
{
    double x;
    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "y = " << f(x) << std::endl;
    return 0;
}
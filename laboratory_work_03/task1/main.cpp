#include <iostream>
#include <iomanip>
#include <cmath>


double f(double x)
{
    if (x <= -2) return - 0.5 * x - 1.5;
    if (x >= 2) return 0.5 * x - 1.5;
    return 2 * std::cos(2 * x);
}


int main()
{
    const double start = -4., finish = 4.;
    double dx;
    std::cout << "Enter step of func: ";
    std::cin >> dx;

    std::cout << std::fixed;

    std::cout << "+----------+----------+" << std::endl;
    std::cout << "| x        | y        |" << std::endl;
    std::cout << "+----------+----------+" << std::endl;
    
    for (double i = start; i <= finish; i += dx)
    {
        std::cout << std::setprecision(4) << "| " << std::setw(8)
        << std::right << i;
        std::cout << std::setprecision(4) << " | " << std::setw(8)
        << std::right << f(i) << " |" << std::endl;
        std::cout << "+----------+----------+" << std::endl;
    }

    return 0;
}

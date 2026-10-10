#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>


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
    srand(time(NULL));
    std::cout << std::fixed;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distrib(-10., 10.);

    std::cout << "+----------+----------+----------+----------+" << std::endl;
    std::cout << "| x        | y        | r        | belong   |" << std::endl;
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    
    for (double i = 0; i < 10; i++)
    {
        double x = distrib(gen), y = distrib(gen), r = abs(distrib(gen));
        std::cout << "| " << std::setprecision(5) << std::right 
        << std::setw(8) << x;
        std::cout << " | " << std::setprecision(5) << std::right 
        << std::setw(8) << y;
        std::cout << " | " << std::setprecision(5) << std::right 
        << std::setw(8) << r;
        std::cout << " | " << std::setprecision(5) << std::left 
        << std::setw(8) << ((f(x, y, r)) ? "in" : "out") << " |" << std::endl;
        std::cout << "+----------+----------+----------+----------+" << std::endl;
    }

    return 0;
}

#include <iostream>
#include <cmath>
#include <iomanip>

double ch(double x, double n) 
{
    double sum = 1., term = 1.;

    for (int i = 1; i <= n; i++)
    {
        term *= (x * x) / ((2 * i) * (2 * i - 1));
        sum += term;
    }
    return sum;
}

int main() 
{
    double start, finish, dx, eps;
    std::cout << "Enter start of func: "; std::cin >> start;
    std::cout << "Enter finish of func: "; std::cin >> finish;
    std::cout << "Enter step of func: "; std::cin >> dx;
    std::cout << "Enter accurancy: "; std::cin >> eps;
    std::cout << std::fixed;
    std::cout << "+----------+----------+----------+" << std::endl;
    std::cout << "| x        | ch(x)    | eps      |" << std::endl;
    std::cout << "+----------+----------+----------+" << std::endl;


    for (double i = start; i <= finish; i += dx)
    {
        std::cout << "| " << std::setprecision(5) << std::setw(8)
        << std::right << i;
        std::cout << " | " << std::setprecision(5) << std::setw(8)
        << std::right << ch(i, eps);
        std::cout << " | " << std::setprecision(5) << std::setw(8)
        << std::right << eps << " |" << std::endl;
        std::cout << "+----------+----------+----------+" << std::endl;
    }
    return 0;
}

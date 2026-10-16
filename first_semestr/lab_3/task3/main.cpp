#include <iostream>
#include <cmath>
#include <iomanip>

double ch(double x, double eps) 
{
    double sum = 1.0;
    double term = 1.0;
    int n = 1;

    do 
    {
        term *= (x * x) / ((2 * n - 1) * (2 * n));
        sum += term;
        n++;
    } 
    while (std::abs(term) >= eps && n < 1000);
    return sum;
}

int main() 
{
    double start, finish, dx, eps;
    std::cout << "Enter start of func: "; std::cin >> start;
    std::cout << "Enter finish of func: "; std::cin >> finish;
    std::cout << "Enter step of func: "; std::cin >> dx;
    std::cout << "Enter accuracy (e.g. 0.00001): "; std::cin >> eps;
    
    if (dx <= 0) 
    {
        std::cout << "Step must be greater than 0!" << std::endl;
        return 1;
    }

    std::cout << std::fixed;
    std::cout << "+----------+----------+----------+" << std::endl;
    std::cout << "| x        | ch(x)    | eps      |" << std::endl;
    std::cout << "+----------+----------+----------+" << std::endl;

    for (double i = start; i <= finish + dx / 2; i += dx)
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

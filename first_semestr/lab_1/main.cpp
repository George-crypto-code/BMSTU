#include <iostream>
#include <cmath>


int main() 
{
    double a;
    std::cout << "Enter a (pi; 3 * pi / 2): ";
    std::cin >> a;
    while (M_PI >= a || 3 * M_PI / 2 <= a)
    {
        std::cout << "Wrong input! Try again!" << std::endl;
        std::cin >> a;
    }

    double y = std::sqrt((1.0 - std::sin(M_PI / 2.0 - a)) / 2.0)
    + std::sqrt((1.0 + std::cos(2.0 * M_PI - a)) / 2.0);

    std::cout << "y = " << y << std::endl;

    return 0;
}

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>


double f(double x)
{
    return std::sqrt((1.0 - std::sin(M_PI / 2.0 - x)) / 2.0)
    + std::sqrt((1.0 + std::cos(2.0 * M_PI - x)) / 2.0);
}


int main()
{
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) return 1;
    std::string number; std::getline(inputFile, number);

    double a = std::stod(number);

    std::ofstream outputFile("output.txt");
    if (!inputFile.is_open()) return 1;

    outputFile << f(a);

    inputFile.close();
    outputFile.close();
    return 0;
}

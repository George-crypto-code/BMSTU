#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>


// beautiful print of array
// like in Python
void pprint(double array[], int size)
{
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "[";
    for (int i = 0; i < size - 1; i++)
        std::cout << ((i % 5 == 0 && i != 0) ? "\n " : "")
        << std::setw(8) << std::right << array[i] << "...  ";
    
    std::cout << (((size - 1) % 5 == 0) ? "\n " : "") << std::setw(8) 
    << std::right << array[size - 1] << "...]" << std::endl;
}


// calculate average value of data
double mean(double array[], int size)
{
    double s = 0;
    for (int i = 0; i < size; i++)
        s += array[i];
    return s / size; 
}


// sum of square's substraction
double sumSquSub(double array[], int size, double mean)
{
    double s = 0;
    for (int i = 0; i < size; i++)
        s += std::pow(array[i] - mean, 2);
    return s;
}


// sort array by bubble sort
void sort(double array[], int size)
{
    for (int j = 0; j < size; j++)
        for (int i = 0; i < size - 1; i++)
            if (array[i + 1] > array[i])
            {
                double temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
}


int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distrib(-5., 5.);

    int n;
    std::cout << "\nEnter size of array between 0 and 30: ";
    std::cin >> n;
    while (n < 0 || n > 30)
    {
        std::cout << "Incorrect input!\nTry again!" << std::endl;
        std::cin >> n;
    }
    double array[n];

    for (int i = 0; i < n; i ++) array[i] = distrib(gen);
    
    std::cout << "start array:" << std::endl;
    pprint(array, n);

    double mn = mean(array, n);
    std::cout << std::setprecision(5) << "\n\nMean of array: \n" 
    << mn << "..." << std::endl;

    std::cout << std::setprecision(5) 
    << "\n\nSum of square's subtraction: \n" 
    << sumSquSub(array, n, mn) << "..." << std::endl;

    sort(array, n);
    for (int i = 0; i < n; i++) array[i] -= mn;
    std::cout << "\n\nSorted array:" << std::endl;
    pprint(array, n);

    return 0;
}
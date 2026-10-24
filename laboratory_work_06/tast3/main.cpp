#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <iomanip>
#include <fstream>
#include <string>


std::vector<std::vector<int>> makeMatrix(int n)
{
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < n; j++)
            row.push_back(std::pow(n * i + j + 1, 2));
        matrix.push_back(row);
    }
    return matrix;
}


void print(std::vector<std::vector<int>> matrix, std::ofstream& file)
{
    int max = 0;
    for (auto row : matrix)
        for (int elem : row)
            if (std::abs(elem) > max)
                max = std::abs(elem);

    int max_width = std::to_string(max).length();

    file << "[" << std::endl;
    for (size_t i = 0; i < matrix.size(); ++i) 
    {
        file << " [";
        for (size_t j = 0; j < matrix[i].size(); ++j) 
        {
            file << std::right << std::setw(max_width) << matrix[i][j];
            if (j < matrix[i].size() - 1) file << " ";
        }
        file << "]";
        if (i < matrix.size() - 1) file << "," << std::endl;
        else file << std::endl;

    }
    file << "]" << std::endl;
}


int sumDiagonal(std::vector<std::vector<int>> matrix)
{
    int sum = 0;
    for (int i = 0; i < matrix.size(); i++) sum += matrix[i][i];
    return sum;
}


int main()
{
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) return 1;
    std::string line; std::getline(inputFile, line);
    int size = std::stoi(line);
    inputFile.close();

    std::vector<std::vector<int>> matrix = makeMatrix(size);
    std::ofstream outputFile("output.txt");
    outputFile << "Input matrix:\n";
    print(matrix, outputFile);
    outputFile << "Sum of main diagonal:\n" 
    << sumDiagonal(matrix) << std::endl;
    outputFile.close();
    return 0;
}

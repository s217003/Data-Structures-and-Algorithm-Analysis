#include "Matrix.h"
#include <iostream>

int main(int argc, char* argv[])
{
    int r, c;
    std::cin >> r >> c;
    Matrix<int> a(r,c);
    if (a.is_square())
      std::cout << "The matrix is a square matrix" << std::endl;
    else
      std::cout << "The matrix is not a square matrix" << std::endl;
    return 0;
};

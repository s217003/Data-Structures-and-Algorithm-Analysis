/**
 * @file   main.cpp
 * @author Wang Heyu <hywang@wukong>
 * @date   Fri Sep 17 10:53:21 2021
 * 
 * @brief  A c style Gaussian Elimination Prog. 
 * 
 * 
 */

#include <iostream>
#include <cmath>
#include <limits>

/** 
 * To stop the program abnormally.
 * 
 * @param error_code code for error cases.
 */
void abort(int error_code)
{
    switch (error_code)
    {
    case 1:
	std::cout << "The matrix is sigular." << std::endl;
	break;
    default:
	break;
    }
    exit(-1);
};

int main(int argc, char *argv[])
{
    int n = 0;
    std::cin >> n;

    /// Set the machine epsilon.
    const double eps = std::numeric_limits<double>::epsilon();

    double A[n][n];
    double b[n];
    double x[n];
    
    for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	    std::cin >> A[i][j];
    for (int i = 0; i < n; i++)
	std::cin >> b[i];

    std::cout << n << std::endl;

    std::cout.setf(std::ios::fixed);
    std::cout.precision(20);
    for (int i = 0; i < n; i++)
    {
	for (int j = 0; j < n; j++)
	    std::cout << A[i][j] << "\t";
	std::cout << std::endl;
    }

    for (int i = 0; i < n; i++)
	std::cout << b[i] << "\t";
    std::cout << std::endl;

    /// A gaussian elimination procedure without pivoting.
    for (int k = 0; k < n - 1; k++)
    {
	/// Check the linear dependency of the system.
	if (std::fabs(A[k][k]) < eps)
	    abort(1);
	for (int i = k + 1; i < n; i++)
	{
	    for (int j = k + 1; j < n; j++)
		A[i][j] -= A[k][j] * A[i][k] / A[k][k];
	    b[i] -= b[k] * A[i][k] / A[k][k];
	}
    }
    if (std::fabs(A[n - 1][n - 1]) < eps)
	abort(1);

    /// Backward substitution.
    for (int i = n - 1; i >= 0; i--)
    {
	double sum = 0.0;
	for (int j = i + 1; j < n; j++)
	    sum += A[i][j] * x[j];
	x[i] = (b[i] - sum) / A[i][i];
    }

    for (int i = 0; i < n; i ++)
	std::cout << x[i] << "\t";
    std::cout << std::endl;
    return 0;
};

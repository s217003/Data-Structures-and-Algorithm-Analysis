#include <iostream>
#include <cmath>
#include <limits>

int main(int argc, char *argv[])
{
    int n = 0;
    std::cin >> n;
    const double eps = std::numeric_limits<double>::epsilon();

    double A[n][n];
    double b[n];
    double x[n];
    double residual = 0.0;
    
    for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	    std::cin >> A[i][j];
    for (int i = 0; i < n; i++)
	std::cin >> b[i];

    for (int i = 0; i < n; i++)
	std::cin >> x[i];

    /// Compute the residual with l2-norm.
    for (int i = 0; i < n; i++)
    {
	double ei = 0.0;
	for (int j = 0; j < n; j++)
	    ei += A[i][j] * x[j];
	ei -= b[i];
	residual += ei * ei;
    }
    residual = std::sqrt(residual);

    std::cout << residual << std::endl;

    if (residual < eps * n * n)
	std::cout << "Passed." << std::endl;
    else
	std::cout << "Failed." << std::endl;

    return 0;
};


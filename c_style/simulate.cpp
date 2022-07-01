#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>

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
	std::cout << "Need 1 argument." << std::endl;
	break;
    default:
	break;
    }
    exit(-1);
};

int main(int argc, char *argv[])
{
    /// Set an internal clock to generator a random seed.
    typedef std::chrono::high_resolution_clock myclock;
    myclock::time_point beginning = myclock::now();

    /// The first main argument is the dimension of the system.
    if (argc < 2)
	abort(1);
    int n = std::atoi(argv[1]);

    double A[n][n];
    double b[n];

    /// Generate a random seed.
    myclock::duration d = myclock::now() - beginning;
    unsigned seed = d.count();

    /// Setup the random generator.
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0.0,1.0);

    /// Generate a linear system with the given dimension n randomly.
    for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	    A[i][j] = distribution(generator);
    for (int i = 0; i < n; i++)
	b[i] = distribution(generator);

    /// Output the linear system data for the next program.
    /// Set the output format and precision for the double accuracy.
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
    return 0;
};

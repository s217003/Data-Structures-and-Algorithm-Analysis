#include "Matrix.h"

int main(int argc, char* argv[])
{
  SquareMatrix B;
  SquareMatrix A(3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
       A.set_matrix_elements(i, j, i + j);
  std::cout << A.get_dimension() << std::endl;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
      std::cout << A.get_matrix_elements(i, j) << "\t";
    std::cout << std::endl;
  };
  return 0;
};

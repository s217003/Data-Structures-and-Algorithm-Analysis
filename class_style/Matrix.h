#include<iostream>

class SquareMatrix
{
private:
  int dimension;
  double* matrix_elements;
public:
  ~SquareMatrix()
  {
    delete [] matrix_elements;
    matrix_elements = nullptr;
  };
  SquareMatrix()
  {
    dimension = 0;
    matrix_elements = nullptr;
  };
  SquareMatrix(int _d)
  {
    allocMem(_d);
  };
  inline void allocMem(_d)
  {
    dimension = _d;
    matrix_elements = new double [_d * _d];
  };
  void reinit(int _d)
  {
    allocMem(_d);
  };
  
  int get_dimension()
  {
    return dimension;
  };
  
  double get_matrix_elements(int _i, int _j);
  void set_matrix_elements(int _i, int _j, double _v);
};

double SquareMatrix::get_matrix_elements(int _i, int _j)
{
  return matrix_elements[_i * dimension + _j];
};

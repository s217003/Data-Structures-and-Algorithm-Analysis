#include<iostream>
template<typename T>

class Matrix
{
 public:
  int n_row = 0;
  int n_col = 0;
  T** matrix_elements = nullptr;
  
  
 public:
  Matrix(){};
  Matrix(int n_row, int n_col);
  ~Matrix()
  {
    clearMemory();
  };

  void clearMemory()
  {
    for (int i = 0; i < n_row; i++)
    {
      delete[] matrix_elements[i];
    }
    delete [] matrix_elements;
    n_row = 0;
    n_col = 0;
  };
  const Matrix& operator*(const Matrix& _obj);
  bool is_square();
  void matrix_new(int _r, int _c, const T& _val);
  void matrix_delete(int _r, int _c);
  void printMatrix();
};

template <typename T>
Matrix<T>::Matrix(int row, int col)
{
  n_row = row;
  n_col = col;
  matrix_elements = new T*[row];
  for (int i = 0; i < n_row; i++)
    {
      matrix_elements[i] = new T[n_col];
    }
};

template <typename T>
void Matrix<T>::printMatrix()
{
  if (n_row == 0 && n_col == 0)
    return;
  for (int i = 0; i < n_row; i++)
  {
    {
    for (int j = 0; j < n_col; j++)
      std::cout << matrix_elements[i][j] << '\t';
    }
    std::cout << '\n' << std::endl;
  }
  std::cout << "\b\b." << std::endl;
};

template <typename T>
bool Matrix<T>::is_square()
{
  if (n_row == n_col)
    return true;
  else
    return false;
};

template <typename T>
void Matrix<T>::matrix_new(int _r, int _c, const T& _val)
{
  matrix_elements[_r][_c] = _val;
};

template <typename T>
void Matrix<T>::matrix_delete(int _r, int _c)
{
  matrix_elements[_r][_c] = 0;
};

template <typename T>
const Matrix<T>& Matrix<T>::operator*(const Matrix<T>& _obj)
{
    Matrix<T> a(this->n_row,_obj.n_col);
    //if (this->n_col == _obj.n_row)
	//{
	for (int i = 0; i < a.n_row; i++ )
	{
	    for (int j = 0; j < a.n_col; j++)
	    {
		a.matrix_elements[i][j] = 0;
		for(int k=0;k<this->n_col;k++)
		    a.matrix_elements[i][j] += this->matrix_elements[i][k]*_obj.matrix_elements[k][j];
	    }
	}
	// for (int i = 0; i < this->n_row; i++)
        // {
	//     for (int j = 0; j < _obj.n_col; j++)
	//     {
	// 	a.matrix_elements[i][j] += this->elements[i][k]*_obj.elements[k][j];
	//     }
	//}
	return a;
	//}
    // else
    // {
    // 	std::cout << "can't multiply" << std::endl;
    // 	return 0;
    // }
};

// class RowVector : public Matrix

// class ColVector : public Matrix

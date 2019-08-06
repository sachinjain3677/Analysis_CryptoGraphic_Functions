#ifndef LIB_SPARSE_MATRIX_H
#define LIB_SPARSE_MATRIX_H

#include <vector>

namespace lib {
template <class T>
class SparseMatrix {
 public:

  SparseMatrix(int rows, int cols);

  ~SparseMatrix();

  std::vector<std::pair<int, T> > rows(int row);

  std::vector<std::pair<int, T> > cols(int col);

  void insert(int row, int col, T& value);

  SparseMatrix<T> operator *(SparseMatrix<T>& a);

  SparseMatrix<T> operator +(SparseMatrix<T>& a);

  SparseMatrix<T> KroneckerProduct(SparseMatrix<T>& a);

 private:

  std::vector<std::vector<std::pair<int, T> > > rows_;

  std::vector<std::vector<std::pair<int, T> > > cols_;
};

} // namespace lib

#endif
#ifndef LIB_SPARSE_MATRIX_H
#define LIB_SPARSE_MATRIX_H

#include <vector>

namespace lib {
template <class T>
class SparseMatrix {
 public:

  static SparseMatrix<T> IdentityMatrix(int n);

  SparseMatrix(int rows, int cols);

  ~SparseMatrix();

  std::vector<std::pair<int, T> > rows(int row);

  std::vector<std::pair<int, T> > cols(int col);

  void insert(int row, int col,const T& value);

  // For AX where A is a sparse matrix and X is a column vector.
  std::vector<T> ProductByColumnVector(const std::vector<T>& v);

  SparseMatrix<T> KroneckerProduct(const SparseMatrix<T>& a);

 private:

  std::vector<std::vector<std::pair<int, T> > > rows_;

  std::vector<std::vector<std::pair<int, T> > > cols_;
};

} // namespace lib

#endif
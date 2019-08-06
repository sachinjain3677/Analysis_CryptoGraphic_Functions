#include "sparse_matrix.h"

#include <cstddef>

namespace lib {

template <class T>
SparseMatrix<T>::SparseMatrix(int n, int m) {
  rows_.resize(n);
  cols_.resize(m);
}

template <class T>
SparseMatrix<T> SparseMatrix<T>::IdentityMatrix(int n) {
  SparseMatrix<T> Id(n,n);
  for(int i=0;i<n;i++) {
    Id.insert(i, i, 1);
  }
}

template <class T>
const std::vector<std::pair<int, T> > SparseMatrix<T>::rows(int row) {
  if(row>=rows_.size()) {
    return NULL;
  }
  return rows_[row];
}

template <class T>
const std::vector<std::pair<int, T> > SparseMatrix<T>::cols(int col) {
  if(col>=cols_.size()) {
    return NULL;
  }
  return cols_[col];
}

template <class T>
void SparseMatrix<T>::insert(int row, int col, const T& value) {
  rows_[row].push_back(std::pair<int, T>(col, value));
  cols_[col].push_back(std::pair<int, T>(row, value));
}

// Implement matrix multiplication and kronecker product here and delete the comment.

}  // namespace lib
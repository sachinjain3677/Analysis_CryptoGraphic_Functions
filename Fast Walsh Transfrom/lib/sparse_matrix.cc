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

template <class T>
std::vector<T> SparseMatrix<T>::ProductByColumnVector(const std::vector<T>& v) {
  if(cols_.size()!=v.size()) {
    return NULL;
  }
  std::vector<int> product;
  for(int i=0;i<rows_.size();i++) {
    T sum = 0;
    for(int j=0;j<rows_[i].size();j++) {
      int col = rows_[i][j].first;
      T value = rows_[i][j].second;
      sum += value*v[j];
    }
    product.push_back(sum);
  }
  return product;
}

template <class T> 
SparseMatrix<T> SparseMatrix<T>::KroneckerProduct(const SparseMatrix<T>& a) {
  SparseMatrix<T> sp(rows_.size()*a.rows_.size(),
    cols_.size()*a.cols_size());
  for(int i=0;i<rows_.size();i++) {
    for(int j=0;j<rows_[i].size();j++) {
      int col = rows_[i][j].first;
      T value = rows_[i][j].second;

      // copy matrix a multiplied by value at (i,j) in matrix sp.
      for(int k=0;k<a.rows_.size();k++) {
        int new_row = i*a.rows_.size()+k;
        for(int l=0;l<a.rows_[i].size();l++) {
          int new_col = col*a.cols_.size()+a.rows_[i][j].first;
          int new_value = value*a.rows_[i][j].second;
          sp.insert(new_row, new_col, new_value);
        }
      }
    }
  }
  return sp;
}

}  // namespace lib
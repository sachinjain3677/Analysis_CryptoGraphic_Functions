#ifndef LIB_SPARSE_MATRIX_H
#define LIB_SPARSE_MATRIX_H

#include <vector>

namespace lib {
template <class T>
class SparseMatrix {
 public:

  static SparseMatrix<T> IdentityMatrix(int n);

  SparseMatrix(int rows, int cols);

  ~SparseMatrix() {}

  const std::vector<std::pair<int, T> > rows(int row);

  const std::vector<std::pair<int, T> > cols(int col);

  void insert(int row, int col, const T& value);

  // For A*X where A is a sparse matrix and X is a column vector.
  std::vector<T> ProductByColumnVector(const std::vector<T>& v);

  SparseMatrix<T> KroneckerProduct(const SparseMatrix<T>& a);

 private:

  std::vector<std::vector<std::pair<int, T> > > rows_;

  std::vector<std::vector<std::pair<int, T> > > cols_;
};

}  // namespace lib

// TODO(): Remove this part after linking sparse_matrix.cc
// start
#include <cstddef>

namespace lib {

template <class T>
SparseMatrix<T>::SparseMatrix(int n, int m) {
  rows_.resize(n);
  cols_.resize(m);
}

template <class T>
SparseMatrix<T> SparseMatrix<T>::IdentityMatrix(int n) {
  SparseMatrix<T> Id(n, n);
  for(int i=0;i<n;i++) {
    Id.insert(i, i, 1);
  }
  return Id;
}

template <class T>
const std::vector<std::pair<int, T> > SparseMatrix<T>::rows(int row) {
  if(row>=rows_.size()) {
    std::vector<std::pair<int, T> > null;
    return null;
  }
  return rows_[row];
}

template <class T>
const std::vector<std::pair<int, T> > SparseMatrix<T>::cols(int col) {
  if(col>=cols_.size()) {
    std::vector<std::pair<int, T> > null;
    return null;;
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
    std::vector<T> null;
    return null;
  }
  std::vector<int> product;
  for(int i=0;i<rows_.size();i++) {
    T sum = 0;
    for(int j=0;j<rows_[i].size();j++) {
      int col = rows_[i][j].first;
      T value = rows_[i][j].second;
      sum += value*v[col];
    }
    product.push_back(sum);
  }
  return product;
}

template <class T> 
SparseMatrix<T> SparseMatrix<T>::KroneckerProduct(const SparseMatrix<T>& a) {
  SparseMatrix<T> sp(rows_.size()*a.rows_.size(),
    cols_.size()*a.cols_.size());
  for(int i=0;i<rows_.size();i++) {
    for(int j=0;j<rows_[i].size();j++) {
      int col = rows_[i][j].first;
      T value = rows_[i][j].second;

      // copy matrix a multiplied by value at (i,j) in matrix sp.
      for(int k=0;k<a.rows_.size();k++) {
        int new_row = i*a.rows_.size()+k;
        for(int l=0;l<a.rows_[k].size();l++) {
          int new_col = col*a.cols_.size()+a.rows_[k][l].first;
          int new_value = value*a.rows_[k][l].second;
          sp.insert(new_row, new_col, new_value);
        }
      }
    }
  }
  return sp;
}
// end
}  // namespace lib
#endif
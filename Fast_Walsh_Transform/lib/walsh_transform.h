#ifndef LIB_WALSH_TRANSFORM_H
#define LIB_WALSH_TRANSFORM_H

#include "sparse_matrix.h"

namespace lib{
template <class T>
std::vector<T> FastWalshTransform(std::vector<T> v) {
  // Finding n such that 2^n is greater than or equal to
  // size of input vector.
  int temp = v.size();
  int n=0;
  while(temp!=1) {
    temp/=2;
    n++;
  }
  int N = 1<<n;
  while(v.size() != N) {
    v.push_back(0.0);
  }
  // Initialising H_1.
  SparseMatrix<T> H_1(2,2);
  H_1.insert(0, 0, 1);
  H_1.insert(0, 1, 1);
  H_1.insert(1, 0, 1);
  H_1.insert(1, 1, -1);
  // Hn = Mn(1)*Mn(2)*...Mn(n)
  // W(f) = Hn*f
  // Iterating over Mn(i)s and taking product with vector v. 
  for(int i=n;i>0;i--) {
    // Mn(i) = I(n-i) X H_1 X I(i-1)
    SparseMatrix<T> Id_1 = SparseMatrix<T>::IdentityMatrix(1<<(i-1));
    SparseMatrix<T> Id_2 = SparseMatrix<T>::IdentityMatrix(1<<(n-i));
    SparseMatrix<T> temp = H_1.KroneckerProduct(Id_1);
    SparseMatrix<T> Mn_i = Id_2.KroneckerProduct(temp);
    v = Mn_i.ProductByColumnVector(v);
  }
  return v;
}

}  // namespace lib

#endif
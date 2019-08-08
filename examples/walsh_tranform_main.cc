#include "../lib/walsh_transform.h"

#include<iostream>

int main () {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(0);
  v.push_back(1);
  v.push_back(1);
  std::cout << "Input function:\n";
  for(int i=0;i<v.size();i++)
    std::cout << v[i]<< ' ';
  std::cout << "\n";
  std::cout << "Output function:\n";
  v = lib::FastWalshTransform(v);
    for(int i=0;i<v.size();i++)
    std::cout << v[i]<< ' ';
  std::cout << "\n\n";

  // TODO():replace push_backs above and below with this method.
  int f2[] = {-1,1,-1,-1};
  v = std::vector<int> (f2,f2+4);

  std::cout << "Input function:\n";
  for(int i=0;i<v.size();i++)
    std::cout << v[i]<< ' ';
  std::cout << "\n";
  std::cout << "Output function:\n";
  v = lib::FastWalshTransform(v);
    for(int i=0;i<v.size();i++)
    std::cout << v[i]<< ' ';
  std::cout << "\n\n";
  v.clear();
  v.push_back(1);
  v.push_back(1);
  v.push_back(0);
  v.push_back(1);
  v.push_back(0);
  v.push_back(0);
  v.push_back(1);
  v.push_back(0);
  std::cout << "Input function:\n";
  for(int i=0;i<v.size();i++)
    std::cout << v[i]<< ' ';
  std::cout << "\n";
  std::cout << "Output function:\n";
  v = lib::FastWalshTransform(v);
  for(int i=0;i<v.size();i++)
    std::cout << v[i]<< ' ';
}

#include <vector>
#include <iostream>

int main() {
  std::vector<int> v1(100);
  std::vector<int> v2(100);
  printf("v1[0] %p\n", &v1[0]);
  printf("v2[0] %p\n", &v2[0]);
  printf("addr offset %ld\n", abs(&v1[0] - &v2[0]));

  int v3[100];
  int v4[100];
  printf("v3[0] %p\n", &v3[0]);
  printf("v4[0] %p\n", &v4[0]);
  printf("addr offset %ld\n", abs(&v3[0] - &v4[0]));

  std::vector<std::vector<int> > v5(100);
  for (int i = 0; i < 100; i++) {
    v5[i].resize(100);
  }
  printf("v5[0] %p\n", &v5[0]);
  printf("v5[1] %p\n", &v5[1]);
  printf("addr offset %ld\n", abs(&v5[0] - &v5[1]));
}
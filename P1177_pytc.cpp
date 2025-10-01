#include <iostream>
using namespace std;

void merge(int vec[], int start, int mid, int end) {

  int tmp[5] = {};
  int Lb = start, Rb = mid;
  int tidx = 0;

  // Merge Number
  while (Lb < mid && Rb < end) {
    if (vec[Lb] < vec[Rb]) {
      tmp[tidx++] = vec[Lb++];
    } else {
      tmp[tidx++] = vec[Rb++];
    }
  }

  while (Lb < mid) {
    tmp[tidx++] = vec[Lb++];
  }
  while (Rb < end) {
    tmp[tidx++] = vec[Rb++];
  }

  for (int i = start; i < end; ++i)
    vec[i] = tmp[i - start];
}

void mergesort(int vec[], int start, int end) {

  if (start + 1 >= end)
    return;

  int mid = start + (end - start) / 2;

  mergesort(vec, start, mid);
  mergesort(vec, mid, end);

  merge(vec, start, mid, end);
}

int main() {

  int n = 5;
  int vec[5] = {4, 2, 4, 5, 1};

  mergesort(vec, 0, n);

  for (int i = 0; i < n; ++i)
    cout << vec[i] << " ";

  return 0;
}

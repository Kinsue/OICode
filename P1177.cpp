#include <iostream>
#include <vector>
using namespace std;

void mergesort(vector<int> &vec, int start, int end) {

  if (start + 1 >= end)
    return;

  vector<int> tmp;
  int mid = start + (end - start) / 2;

  mergesort(vec, start, mid);
  mergesort(vec, mid, end);

  // Merge Number
  int Lb = start, Rb = mid;
  while (Lb < mid && Rb < end) {
    if (vec[Lb] < vec[Rb]) {
      tmp.push_back(vec[Lb++]);
    } else {
      tmp.push_back(vec[Rb++]);
    }
  }

  while (Lb < mid) {
    tmp.push_back(vec[Lb++]);
  }
  while (Rb < end) {
    tmp.push_back(vec[Rb++]);
  }

  for (int i = start; i < end; ++i)
    vec[i] = tmp[i - start];
}

int main() {

  int n;
  cin >> n;
  vector<int> vec(n, 0);

  for (int i = 0; i < n; ++i)
    cin >> vec[i];

  mergesort(vec, 0, n);

  for (auto item : vec)
    cout << item << " ";

  return 0;
}

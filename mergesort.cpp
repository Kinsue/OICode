#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &vec, int start, int mid, int end) {

  vector<int> tmp;
  int lb = start;
  int rb = mid;
  while (lb < mid && rb < end) {
    if (vec[lb] > vec[rb]) {
      tmp.push_back(vec[rb++]);
    } else {
      tmp.push_back(vec[lb++]);
    }
  }
  while (lb < mid)
    tmp.push_back(vec[lb++]);
  while (rb < end)
    tmp.push_back(vec[rb++]);

  for (int i = start; i < end; ++i) {
    vec[i] = tmp[i - start];
  }
}

void mergesort(vector<int> &vec, int start, int end) {

  if (end - start <= 1)
    return;

  int mid = start + (end - start) / 2;

  mergesort(vec, start, mid);
  mergesort(vec, mid, end);

  merge(vec, start, mid, end);
}

int main() {

  int n;
  cin >> n;

  vector<int> vec(n, 0);

  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }

  mergesort(vec, 0, n);

  for (auto item : vec) {
    cout << item << " ";
  }
  cout << endl;

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int> &vec, int start, int mid, int end) {

  long long ans = 0;

  vector<int> tmp;
  int lb = start;
  int rb = mid;

  while (lb < mid && rb < end) {
    if (vec[lb] > vec[rb]) {
      tmp.push_back(vec[rb++]);
      ans += mid - lb;
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
  return ans;
}

long long mergesort(vector<int> &vec, int start, int end) {

  if (end - start <= 1)
    return 0;

  int mid = start + (end - start) / 2;
  long long ans = 0;

  ans += mergesort(vec, start, mid);
  ans += mergesort(vec, mid, end);

  return ans + merge(vec, start, mid, end);
}

int main() {

  int n;
  cin >> n;

  vector<int> vec(n, 0);

  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }

  cout << mergesort(vec, 0, n);

  return 0;
}

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> vec(200001, 0);

  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }

  int mmax = INT_MIN;

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int sum = 0;
      for (int k = i; k <= j; ++k) {
        sum += vec[k];
      }
      mmax = max(mmax, sum);
    }
  }

  cout << mmax;

  return 0;
}

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

  int mmax = vec[0];

  for (int i = 1; i < n; ++i) {
    vec[i] = max(vec[i], vec[i - 1] + vec[i]);
    mmax = max(vec[i], mmax);
  }

  cout << mmax;

  return 0;
}

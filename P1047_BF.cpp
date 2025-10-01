#include <bits/stdc++.h>
using namespace std;

int main() {

  int l, m;
  cin >> l >> m;

  int range[10004] = {};
  int left, right;
  for (int i = 0; i < m; ++i) {
    cin >> left >> right;
    for (int i = left; i <= right; ++i) {
      range[i] = 1;
    }
  }

  int result = 0;
  for (int i = 0; i <= l; ++i) {
    if (!range[i])
      result++;
  }
  cout << result;
  return 0;
}

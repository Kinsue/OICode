#include <bits/stdc++.h>

using namespace std;

int main() {

  int mmap[20][20] = {};
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mmap[i][j];
    }
  }

  int f[1 << 20][n];
  memset(f, 0x3f, sizeof(f));

  f[1][0] = 0;
  for (int i = 1; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        for (int k = 0; k < n; ++k) {
          if (i >> k & 1) {
            f[i][j] = min(f[i ^ (1 << j)][k] + mmap[k][j], f[i][j]);
          }
        }
      }
    }
  }

  cout << f[(1 << n) - 1][n - 1];

  return 0;
}

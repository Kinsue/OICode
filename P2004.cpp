#include <bits/stdc++.h>
#include <climits>
using namespace std;

long long vec[1005][1005];
long long sum[1005][1005];

int main() {

  int n, m, c;
  cin >> n >> m >> c;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> vec[i][j];
      sum[i][j] = vec[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  }

  long long mmax = -INT_MAX;
  long long cnt;
  int idx = 1, idy = 1;
  for (int i = c; i <= n; ++i) {
    for (int j = c; j <= m; ++j) {

      cnt = sum[i][j] - sum[i - c][j] - sum[i][j - c] + sum[i - c][j - c];

      if (mmax < cnt) {
        mmax = cnt;
        idx = i - c + 1;
        idy = j - c + 1;
      }
    }
  }

  cout << idx << " " << idy << endl;

  return 0;
}

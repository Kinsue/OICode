#include <bits/stdc++.h>
#include <climits>
#include <sys/types.h>
using namespace std;

int vec[130][130];
int pre[130][130];

int main() {

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> vec[i][j];
      pre[i][j] = vec[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    }
  }

  int mmax = -INT_MAX;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      for (int x = i; x <= n; ++x)
        for (int y = j; y <= n; ++y)
          mmax = max(mmax, pre[x][y] - pre[x][j - 1] - pre[i - 1][y] +
                               pre[i - 1][j - 1]);

  cout << mmax << endl;
  return 0;
}

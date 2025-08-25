#include <bits/stdc++.h>
using namespace std;

int num[1003][1003];
int n;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      cin >> num[i][j];
    }
  }

  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      num[i][j] += max(num[i - 1][j], num[i - 1][j - 1]);
    }
  }

  int mmax = -1;
  for (int i = 1; i <= n; ++i) {
    mmax = max(num[n][i], mmax);
  }
  cout << mmax << endl;

  return 0;
}

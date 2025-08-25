#include <bits/stdc++.h>
using namespace std;

int num[1003][1003];
int mmax[1003][1003];
int n;

int sol(int r, int c) {

  if (mmax[r][c] != -1)
    return mmax[r][c];

  if (r == n) {
    return num[r][c];
  }

  return mmax[r][c] = num[r][c] + max(sol(r + 1, c), sol(r + 1, c + 1));
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      cin >> num[i][j];
    }
  }

  memset(mmax, -1, sizeof(mmax));
  cout << sol(1, 1);

  return 0;
}

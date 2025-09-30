#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;

int shx[] = {-1, 0, 0, 0, 1};
int shy[] = {0, -1, 0, 1, 0};

void op(vector<string> &mp, int x, int y) {

  for (int i = 0; i < 5; ++i) {
    if (x + shx[i] >= 0 && x + shx[i] < 5 && y + shy[i] >= 0 &&
        y + shy[i] < 5) {

      mp[x + shx[i]][y + shy[i]] ^= 1;
    }
  }
}

bool judge(vector<string> mp) {
  for (int i = 0; i < 5; ++i) {
    for (auto item : mp[i])
      if (item == '0')
        return false;
  }

  return true;
}

int search(vector<string> &mp) {

  int result = 0;

  for (int i = 1; i < 5; ++i) {
    for (int k = 0; k < 5; ++k) {
      if (mp[i - 1][k] == '0') {
        op(mp, i, k);
        result++;
      }
    }
  }

  return result;
}

int main() {

  int n;
  cin >> n;
  while (n--) {
    vector<string> mp(5), tmp(5);

    for (int i = 0; i < 5; ++i) {
      cin >> mp[i];
    }

    int result, mmin = 7;
    for (int i = 0; i < 32; ++i) {
      tmp = mp;
      result = 0;
      for (int k = 0; k < 5; ++k) {
        if (i >> k & 1) {
          op(tmp, 0, 4 - k);
          result++;
        }
      }

      result += search(tmp);
      if (judge(tmp))
        mmin = min(mmin, result);
    }

    if (mmin == 7) {
      cout << -1 << endl;
    } else {
      cout << mmin << endl;
    }
  }

  return 0;
}

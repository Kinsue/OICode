#include <bits/stdc++.h>

using namespace std;

int main() {

  int num[111] = {};

  int n;
  int tmp, sum = 0;
  cin >> n;

  while (n--) {
    cin >> tmp;

    if (num[tmp] == 0) {
      num[tmp]++;
      sum++;
    }
  }

  cout << sum << endl;

  for (int i = 0; i <= 100; ++i) {
    if (num[i])
      cout << i << " ";
  }

  cout << endl;

  return 0;
}

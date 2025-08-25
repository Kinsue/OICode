#include <bits/stdc++.h>
using namespace std;

int main() {

  string a;
  long long b;
  cin >> a;
  cin >> b;

  int num[10001] = {};
  int result[10001] = {};

  for (int i = 0; i < a.size(); ++i) {
    num[i] = a[a.size() - i - 1] - '0';
  }

  long long A = 0;
  for (int i = a.size() - 1; i >= 0; --i) {
    A = A * 10 + num[i];

    if (A / b) {
      result[i] = A / b;
      A %= b;
    }
  }

  int i = a.size();
  while (i > 0 && result[i] == 0)
    i--;

  for (; i >= 0; --i) {
    cout << result[i];
  }

  return 0;
}

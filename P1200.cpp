#include <bits/stdc++.h>

using namespace std;

int main() {

  string s1, s2;
  int mul1 = 1, mul2 = 1;
  cin >> s1 >> s2;

  for (int i = 0; i < s1.size(); ++i) {
    mul1 *= s1[i] - 'A' + 1;
  }

  for (int i = 0; i < s2.size(); ++i) {
    mul2 *= s2[i] - 'A' + 1;
  }

  if (mul1 % 47 == mul2 % 47)
    cout << "GO" << endl;
  else
    cout << "STAY" << endl;

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

  string s, result;
  ll len;
  bool flag = false;

  while (cin >> s) {

    len = s.size();

    if (s[len - 1] == '.') {
      s = s.substr(0, len - 1);
      flag = true;
    }

    if (s.size() > result.size()) {
      result = s;
    }
  }

  cout << result;

  return 0;
}

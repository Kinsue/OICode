#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int main() {

  string s;
  long long len;

  cin >> len;
  cin >> s;

  long long ans = 0;

  for (auto item : s) {
    if (isupper(item)) {
      ans += -1 * static_cast<int>(item);
    } else {
      ans += item - 'a' + 1;
    }
  }

  cout << ans;

  return 0;
}

#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int main() {

  string s;
  getline(cin, s);

  int ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (isdigit(s[i]) || isalpha(s[i]))
      ans++;
  }
  cout << ans;
  return 0;
}

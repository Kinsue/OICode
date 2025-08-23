#include <bits/stdc++.h>
#include <cctype>

using namespace std;

typedef long long ll;

int main() {

  string s;
  cin >> s;

  ll len = s.size();

  if (isdigit(s[0])) {
    cout << "no";
    return 0;
  } else {

    for (auto item : s.substr(1, len - 1)) {
      if (!(isdigit(item) || isalpha(item) || item == '_')) {
        cout << "no" << endl;
        return 0;
      }
    }

    cout << "yes\n";
  }

  return 0;
}

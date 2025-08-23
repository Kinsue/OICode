#include <cctype>
#include <iostream>
using namespace std;

int main() {

  string s, t;
  cin >> s >> t;

  int T;
  int l1, r1, l2, r2;

  cin >> T;
  while (T--) {

    cin >> l1 >> r1 >> l2 >> r2;

    string subs = s.substr(l1 - 1, r1 - l1 + 1);
    string subt = t.substr(l2 - 1, r2 - l2 + 1);

    if (subs == subt) {
      cout << "ovo\n";
    } else if (subs > subt) {
      cout << "erfusuer" << endl;
    } else {
      cout << "yifusuyi" << endl;
    }
  }

  return 0;
}

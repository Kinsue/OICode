#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {

  int T;
  cin >> T;

  string s;
  int op, n1, n2;

  while (T--) {

    cin >> s;

    if (isalpha(s[0])) {
      cin >> n1 >> n2;
      op = s[0] - 'a'; // 0 1 2
    } else {
      n1 = stoi(s);
      cin >> n2;
    }

    switch (op) {
    case 0:
      s = to_string(n1) + "+" + to_string(n2) + "=" + to_string(n1 + n2);
      cout << s << endl << s.size() << endl;
      break;
    case 1:
      s = to_string(n1) + "-" + to_string(n2) + "=" + to_string(n1 - n2);
      cout << s << endl << s.size() << endl;
      break;
    case 2:
      s = to_string(n1) + "*" + to_string(n2) + "=" + to_string(n1 * n2);
      cout << s << endl << s.size() << endl;
      break;
    }
  }

  return 0;
}

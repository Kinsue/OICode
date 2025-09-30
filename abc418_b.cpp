#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {

  string s;
  cin >> s;

  double rate = 0;
  int pre[111] = {};

  for (int i = 0; i < s.size(); ++i)
    pre[i + 1] = pre[i] + (s[i] == 't' ? 1 : 0);

  int len = s.size();
  for (int i = 0; i < len; ++i) {
    for (int j = i; j < len; ++j) {

      if (j - i + 1 < 3)
        continue;

      string sub = s.substr(i, j - i + 1);
      rate = max(rate, (1.0 * (pre[j + 1] - pre[i]) - 2.0) / (j - i + 1 - 2));
    }
  }
  cout << fixed << setprecision(10) << rate << endl;

  return 0;
}

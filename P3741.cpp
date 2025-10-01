#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;

  string s;
  cin >> s;

  string sp = "";
  int result = 0;

  for (int i = 0; i < s.size();) {

    if (i == s.size() - 1) {
      sp += s[i];
      ++i;
    }

    if (s[i] == 'V' && s[i + 1] == 'K') {
      sp += 'X';
      result++;
      i += 2;
    } else {
      sp += s[i];
      i++;
    }
  }

  if (sp.find("KK") != -1 || sp.find("VV") != s.npos)
    result++;

  cout << result;

  return 0;
}

#include <iostream>
#include <string>
using namespace std;

string tolower(string s) {
  for (int i = 0; i <= s.size(); ++i)
    s[i] = tolower(s[i]);

  return s;
}

int main() {

  string word;
  string s;

  int idx = 0, first = -1, cnt = 0;

  cin >> word;
  getchar();
  getline(cin, s);

  word = tolower(word);
  s = tolower(s);

  while (idx < s.size()) {
    while (s[idx] == ' ')
      idx++;
    for (int i = idx; i < word.size(); ++i) {
      if (s[i] != word[i]) {
        idx += i + 1;
        break;
      }
    }
    cnt++;
    if (first == -1) {
      first = idx;
    }
    idx++;
  }

  if (cnt)
    cout << cnt << " " << first;
  else
    cout << -1;

  return 0;
}

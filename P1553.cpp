#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

void rev_rm0(string &s1) {
  s1 = to_string(stoull(s1));
  reverse(s1.begin(), s1.end());
  s1 = to_string(stoull(s1));
}

int main() {

  string s;
  cin >> s;

  string s1, s2;
  int pos;

  if (s.back() == '%') {
    s1 = s.substr(0, s.size() - 1);
    rev_rm0(s1);
    cout << s1 << "%" << endl;

  } else if ((pos = s.find('.')) != -1) {

    s1 = s.substr(0, pos);
    s2 = s.substr(pos + 1, s.size() - pos);

    rev_rm0(s1);
    rev_rm0(s2);

    cout << s1 << '.' << s2 << endl;

  } else if ((pos = s.find('/')) != -1) {

    s1 = s.substr(0, pos);
    s2 = s.substr(pos + 1, s.size() - pos);

    rev_rm0(s1);
    rev_rm0(s2);

    cout << s1 << '/' << s2 << endl;

  } else {

    rev_rm0(s);
    cout << s << endl;
  }
  return 0;
}

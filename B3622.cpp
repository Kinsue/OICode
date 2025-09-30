#include <iostream>

using namespace std;

int n;

void dfs(string s) {

  if (s.size() == n) {
    cout << s << endl;
    return;
  }

  dfs(s + "N");
  dfs(s + "Y");
}

int main() {

  cin >> n;

  dfs("");

  return 0;
}

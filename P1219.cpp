#include <bits/stdc++.h>

using namespace std;

int row[14];
int ans = 0;
int n;

bool check(int r) {
  for (int i = 1; i < r; ++i) {
    if (i + row[i] == r + row[r] || i - row[i] == r - row[r] ||
        row[r] == row[i])
      return false;
  }
  return true;
}

void print() {
  for (int i = 1; i <= n; ++i) {
    cout << row[i];
    if (n)
      cout << " ";
  }
  cout << endl;
}

void fun(int idx) {

  if (idx == n + 1) {
    ans++;
    if (ans < 4)
      print();
    return;
  }

  for (int i = 1; i <= n; ++i) {
    row[idx] = i;
    if (check(idx)) {
      fun(idx + 1);
    }
    // print();
  }
}

int main() {

  cin >> n;

  row[1] = 1;
  fun(1);

  cout << ans;

  return 0;
}

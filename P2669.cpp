#include <bits/stdc++.h>
#include <sys/types.h>

using namespace std;

int main() {

  int n;
  cin >> n;

  int num = 1;
  int cday = 0;

  int ans = 0;
  for (int i = 0; i < n; ++i) {

    ans += num;
    if (++cday == num) {
      cday = 0;
      num++;
    }
  }

  cout << ans << endl;

  return 0;
}

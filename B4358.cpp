#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {

  int n;
  int tmp;
  int ans = 0;

  cin >> n;

  while (n--) {

    cin >> tmp;
    ans += __builtin_popcount(tmp);
  }

  cout << ans << " " << ans % 2 << endl;
  return 0;
}

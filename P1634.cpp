#include <iostream>

using namespace std;

int main() {

  unsigned int x, n;
  cin >> x >> n;

  unsigned long long ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans = ans + ans * x;
  }

  cout << ans;

  return 0;
}

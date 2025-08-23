#include <cinttypes>
#include <iostream>
using namespace std;

int f[1005];
int constract(int n) {
  if (n == 1) {
    return 1;
  }

  int ans = 0;
  for (int i = 1; i <= n / 2; ++i) {
    if (f[i]) {
      ans += f[i];
    } else {
      ans += f[i] = constract(i);
    }
  }

  return 1 + ans;
}

int main() {

  int n;
  cin >> n;
  cout << constract(n) << endl;

  return 0;
}

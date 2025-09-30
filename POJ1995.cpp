#include <iostream>
using namespace std;

long long quickpow(long long base, long long pow, long long mod) {

  long long result = 1;

  while (pow) {
    if (pow & 1) {
      result = result % mod * base % mod;
    }
    base = base % mod * base % mod;
    pow = pow >> 1;
  }

  return result % mod;
}

int main() {

  int z, n;

  long long a, b, m;
  long long ans = 0;

  cin >> z;
  while (z--) {
    cin >> m;
    cin >> n;
    ans = 0;
    while (n--) {
      cin >> a >> b;
      ans = (ans + quickpow(a, b, m)) % m;
    }

    cout << ans << endl;
  }

  return 0;
}

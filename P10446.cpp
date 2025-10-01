#include <iostream>
using namespace std;

typedef long long ll;

ll quickpow(ll a, ll b, ll mod) {

  ll result = 0;

  while (b) {
    if (b & 1) {
      result = (result + a) % mod;
    }
    a = a * 2 % mod;
    b = b >> 1;
  }

  return result % mod;
}

int main() {

  ll a, b, p;
  cin >> a >> b >> p;

  cout << quickpow(a, b, p);

  return 0;
}

#include <iostream>

using namespace std;

const int N = 2000001;
int light[N];

int main() {

  int n;
  cin >> n;

  double a;
  int t;

  /*
  while (n--) {
    cin >> a >> t;
    int num;
    for (int i = 1; i <= t; ++i) {
      num = a * i;
      light[num] ^= 1;
    }
  }
  for (int i = 0; i <= N; ++i) {
    if (light[i]) {
      cout << i << endl;
      break;
    }
  }
  */

  int ans = 0;
  while (n--) {
    cin >> a >> t;
    for (int i = 1; i <= t; ++i) {
      ans ^= (int)(a * i);
    }
  }
  cout << ans << endl;
}

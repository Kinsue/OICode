#include <iostream>
#include <ostream>

using namespace std;

int main() {

  int n;
  cin >> n;

  for (int i = 0; i <= (1 << 12); ++i) {
    if ((n & i) + (n | i) == 2025) {
      cout << i << endl;
      return 0;
    }
  }

  cout << -1;

  return 0;
}

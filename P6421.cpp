#include <cstring>
#include <iostream>

using namespace std;

int main() {

  int n, k;
  cin >> n >> k;
  int pri[1005];

  memset(pri, 0x3f, sizeof(pri));

  int idx = 2;
  int num = 0;
  while (num < k) {
    for (int i = idx; i <= n; i += idx) {

      if (pri[i] == 0)
        continue;

      pri[i] = 0;
      num++;

      if (num == k) {
        cout << i << endl;
        return 0;
      }
    }

    while (pri[idx] == 0)
      idx++;
  }
  return 0;
}

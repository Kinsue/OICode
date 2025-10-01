#include <iostream>

using namespace std;

int sum[7];
int num[7];

int main() {

  int n;
  cin >> n;
  for (int i = 0; i < 7; ++i) {
    cin >> num[i];
  }

  int res, tmp;
  while (n--) {
    res = 0;
    for (int k = 0; k < 7; ++k) {
      cin >> tmp;
      for (int i = 0; i < 7; ++i) {
        if (tmp == num[i]) {
          res++;
          break;
        }
      }
    }
    if (res > 0)
      sum[7 - res]++;
  }

  for (int i = 0; i < 7; ++i) {
    if (i == 0)
      cout << sum[i];
    else
      cout << " " << sum[i];
  }

  return 0;
}

#include <iostream>
#include <sys/types.h>

using namespace std;

int num[5004][2000];
int len = 1;

void add(int a, int b, int c) {

  for (int i = 0; i < len; ++i) {
    num[c][i] += num[a][i] + num[b][i];
    if (num[c][i] > 9) {
      num[c][i + 1]++;
      num[c][i] -= 10;
    }
  }

  if (num[c][len])
    len++;
}

int main() {

  int n;

  cin >> n;

  num[0][0] = 0;
  num[1][0] = 1;
  num[2][0] = 2;

  for (int i = 3; i <= n; ++i) {
    add(i - 1, i - 2, i);
  }

  while (num[n][len] == 0)
    len--;

  for (int i = len; i >= 0; --i) {
    cout << num[n][i];
  }

  return 0;
}

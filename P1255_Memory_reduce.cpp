#include <cstring>
#include <functional>
#include <iostream>
#include <sys/types.h>

using namespace std;

int num1[2000], num2[2000];
int result[2000];
int len = 1;

void add() {

  for (int i = 0; i < len; ++i) {
    result[i] += num1[i] + num2[i];
    if (result[i] > 9) {
      result[i + 1]++;
      result[i] -= 10;
    }
  }

  if (result[len])
    len++;

  swap(num1, num2);
  swap(num2, result);

  memset(result, 0, sizeof(result));
}

int main() {

  int n;

  cin >> n;

  switch (n) {
  case 0:
    cout << 0 << endl;
    break;
  case 1:
    cout << 1 << endl;
    break;
  case 2:
    cout << 2 << endl;
    break;
  default:
    num1[0] = 1;
    num2[0] = 2;
    for (int i = 3; i <= n; ++i) {
      add();
    }

    while (num2[len] == 0)
      len--;

    for (int i = len; i >= 0; --i) {
      cout << num2[i];
    }
  }

  return 0;
}

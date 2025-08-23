#include <iostream>
#include <vector>
using namespace std;

bool prim(int n) {

  if (n < 2)
    return false;

  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {

  string s;
  vector<int> a(26, 0);
  int mmax = 0, mmin = 1111;

  cin >> s;

  for (auto item : s) {
    a[item - 'a']++;
  }

  for (auto item : a) {
    // cout << item << endl;
    mmax = max(mmax, item);
    if (item > 0 && item < mmin)
      mmin = item;
  }

  int value = mmax - mmin;

  if (prim(value)) {
    cout << "Lucky Word" << endl << value;
  } else {
    cout << "No Answer" << endl << 0;
  }

  return 0;
}

// #include<bits/stdc++.h>
#include <iostream>
using namespace std;

/*
 * Generator of result table
 */
int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int fee(int n) {

  if (n == 0)
    return num[0];

  int ans = 0;

  while (n) {
    ans += num[n % 10];
    n /= 10;
  }

  return ans;
}

void genTable() {

  int c, cost;
  int MaxN = 29;
  int result[125] = {};

  for (int i = 0; i <= 1111111; ++i) {
    for (int j = 0; j <= 1111111; ++j) {

      c = i + j;

      cost = fee(c) + fee(i) + fee(j);

      if (cost <= MaxN - 4) {
        ++result[cost + 4];
      }
    }
  }

  // print
  cout << "int table[] = {\n";

  for (int i = 0; i <= MaxN; ++i) {
    cout << result[i] << ", ";
    if (i % 5 == 0)
      cout << endl;
  }
  cout << "};\n";
}

int table[] = {0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,
               1, 2, 8, 9, 6, 9, 29, 39, 38, 65, 88, 128};

int main() {

  genTable();
  int n;
  cin >> n;
  cout << table[n] << endl;

  return 0;
}

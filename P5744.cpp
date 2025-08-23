#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {

  int n;
  cin >> n;
  struct student {
    string name;
    int age;
    int score;
  } peo[5];

  for (int i = 0; i < n; ++i) {
    cin >> peo[i].name >> peo[i].age >> peo[i].score;

    peo[i].age += 1;
    peo[i].score = min(600, int(peo[i].score * 1.2));
  }

  for (int i = 0; i < n; ++i) {
    printf("%s %d %d\n", peo[i].name.c_str(), peo[i].age, peo[i].score);
  }

  return 0;
}

#include <iostream>

using namespace std;

struct student {
  int yu;
  int shu;
  int eng;
  int sum = 0;
} stu[1001];

int main() {

  int N;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> stu[i].yu >> stu[i].shu >> stu[i].eng;
    stu[i].sum = stu[i].yu + stu[i].shu + stu[i].eng;
  }

  int ans = 0;
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j) {
      if (abs(stu[i].yu - stu[j].yu) <= 5 &&
          abs(stu[i].shu - stu[j].shu) <= 5 &&
          abs(stu[i].eng - stu[j].eng) <= 5 &&
          abs(stu[i].sum - stu[j].sum) <= 10)

        ans++;
    }

  cout << ans;

  return 0;
}

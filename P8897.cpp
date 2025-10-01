#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <vector>

using namespace std;

void std_solve(){

  int n;
  cin >> n;

  vector<long long> vec(n);

  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }

  sort(vec.begin(), vec.end());

  long long ans = vec[0] * 1;
  long long price = vec[0];

  for (int i = 1; i < n; ++i) {
    if (vec[i] * (n - i) > ans) {
      ans = vec[i] * (n - i);
      price = vec[i];
    }
  }

  cout << ans << " " << price << endl;

}

void binary_solve(){

  int n;
  cin >> n;

  vector<long long> vec(n);

  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }

  int Lb = 0, Rb = INT_MAX / 2;
  int mid;
  int price = 0, sum = 0;

  while(Rb - Lb > 0){
    mid = Lb + (Rb - Lb) / 2;

    int tmp = 0;
    for(int item : vec) if(item >= mid) tmp += mid;

    // printf("[%d, %d] : %d", Lb, Rb, mid);

    if(tmp > sum){
      price = mid;
      Lb = mid + 1;
    }else{
      Rb = mid;
    }
  }  
  cout << Rb;    
}

int main() {
  binary_solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int a[MAXN], tmp[MAXN];

void mergeSort(int l, int r) {
  if (l >= r)
    return;
  int mid = (l + r) / 2;

  mergeSort(l, mid);
  mergeSort(mid + 1, r);

  int i = l, j = mid + 1, k = 0;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j])
      tmp[k++] = a[i++];
    else
      tmp[k++] = a[j++];
  }

  while (i <= mid)
    tmp[k++] = a[i++];
  while (j <= r)
    tmp[k++] = a[j++];

  for (int t = 0; t < k; ++t) {
    a[l + t] = tmp[t];
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  mergeSort(0, n - 1);

  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";

  return 0;
}

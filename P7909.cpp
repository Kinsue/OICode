#include<bits/stdc++.h>

using namespace std;

int main(){

	int n, L, R;

	cin >> n >> L >> R;
	
	cout << ((R - L >=  n - (L % n) - 1) ? n - 1 : R % n) << endl;

	return 0;
}

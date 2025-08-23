#include<iostream>

using namespace std;

int main(){

	int n;

	while(cin >> n && n){
		// cout << (n & -n) << endl;
		int idx = 1;
		while( idx <= n){
			if( n & idx){
				cout << idx << endl;
				break;
			}
			idx = idx << 1;
		}
	}

	return 0;
}

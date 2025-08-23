#include<bits/stdc++.h>
using namespace std;


int main(){

	int num;

	cin >> num;

	cout << bitset<32>(num << 16) << endl;

	cout << bitset<32>(num >> 16) << endl;

	cout << ((num << 16) |  (num >> 16)) << endl;

	cout << bitset<32>(num & 0xFFFF) << endl;

	cout << bitset<128>(0xFFFF) << endl;

	return 0;
}

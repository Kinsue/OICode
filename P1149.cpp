#include<iostream>

using namespace std;

int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int fee(int x){
	
	if(x == 0){
		return num[0];
	}

	int result = 0;

	while(x){
		result += num[x%10];
		x /= 10;
	}

	return result;
}


int main(){


	int n;
	cin >> n;

	int ans = 0;
	for(int i = 0; i < 1111; ++i)
		for(int j = 0; j < 1111; ++j){
			if( fee(i) + fee(j) + fee(i+j) == n - 4)
				ans ++;
		}

	cout << ans << endl;

	return 0;
}

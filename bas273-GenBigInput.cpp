// generate big input for bas273
// T = 5000000 ans n < INT_MAX


#include <iostream>
#include <climits>

using namespace std;

int main() {
    
    freopen("bas273-biginput.txt", "w", stdout);
    
    int T = 5000000;
    srand(time(NULL));

    printf("%d\n", T - 1);


    printf("%d\n", rand() % INT_MAX);
    int tmp;
    for(int i = 1; i < T / 2; ++i) {
        tmp = rand() % INT_MAX;
        printf("%d %d\n", tmp, tmp);
    }

    return 0;
}   
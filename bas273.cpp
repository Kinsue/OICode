#include <iostream>

using namespace std;

int main() {

    int T, n;
    scanf("%d", &T);

    int ans = 0;
    while(T--) {
        scanf("%d", &n);
        ans ^= n;
    }

    printf("%d\n", ans);

    return 0;
}
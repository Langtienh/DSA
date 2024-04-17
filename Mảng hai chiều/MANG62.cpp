#include <iostream>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; ++i, putchar('\n')) {
        long long mmax = -1e18;
        for(int j=1; j<=n; ++j) {
            long long a; scanf("%I64d", &a);
            mmax = max(mmax, a);
        }
        cout << mmax;
    }
    
    return 0;
}
    

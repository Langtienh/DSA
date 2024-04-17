#include <iostream>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; ++i, putchar('\n')) {
        long long sum  = 0;
        for(int j=1; j<=n; ++j) {
            long long a; scanf("%I64d", &a);
            if ((a & 1) == 0) sum += a;
        }
        cout << sum;
    }
    
    return 0;
}
    

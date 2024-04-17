#include <iostream>

using namespace std;

long long res = 0;

int main() {
    int n; scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        long long a; scanf("%I64d", &a);
        if ((a & 1) == 0 && (i&1)) res += a;
    }
    cout << res;
    
    return 0;
}
    

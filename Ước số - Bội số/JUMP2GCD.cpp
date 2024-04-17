#include <iostream>
#include <algorithm>

using namespace std;

int n, k, d1, d2;

int main() {
    int res = 0;
    scanf("%d%d%d%d", &n, &k, &d1, &d2); d1 = __gcd(d1, d2);
    for(int i=1; i<=n; ++i) {
        int a; scanf("%d", &a);
        if (abs(a - k) % d1 == 0) ++res;
    }
    cout << res;

    return 0;
}
    

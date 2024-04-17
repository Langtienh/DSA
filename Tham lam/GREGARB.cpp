#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, k;

int main() {

    scanf("%d%d", &n, &k);
    llong res = 0; int mod = 0;
    for(int i=1; i<=n; ++i) {
        int a; scanf("%d", &a);
        if (mod > 0 && a + mod < k) res++, mod = 0;
        else {
            res += (a + mod) / k;
            mod = (a + mod) % k;
        }
    }
    if (mod > 0) ++res;
    cout << res;

    return 0;
}
    

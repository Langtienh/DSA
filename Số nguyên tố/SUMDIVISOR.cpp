#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int prime[10000006], cnt = 0, l, r, f[10000006];

void eratos() {
    for(int i=2; i * 2 <= r; ++i) {
        if (!f[i]) f[i] = prime[++cnt] = i;
        int j = 1;
        while (j <= cnt && prime[j] <= f[i] && prime[j] * i * 2<= r) {
            f[prime[j]*i] = prime[j];
            ++j;
        }
    }
}

void find_res() {
    llong res = 0;
    for(int i=1; i<=cnt; ++i) {
        int l1 = (l + (prime[i]-1)) / prime[i] * prime[i];
        int r1 = r - (r % prime[i]);
        res += 1LL*prime[i]*((1LL*r1 - l1) / prime[i] + 1);
        if (l1 <= prime[i] && prime[i] <= r1) res -= prime[i];
    }
    cout << res;
}

int main() {
    scanf("%d%d", &l, &r);
    eratos();
    find_res();
    return 0;
}
    

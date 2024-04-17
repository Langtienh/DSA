#include <iostream>
#include <algorithm>
#define fname "SEMIPRIME"
#define llong long long

using namespace std;

int prime[1000006], f[5000006], cnt = 0, n;

void sieve() {
    for(int i=2; i*2<=n; ++i) {
        if (f[i] == 0) prime[++cnt] = f[i] = i;
        int j = 1;
        while (j <= cnt && prime[j] <= f[i] && prime[j] * i * 2<= n) {
            f[prime[j]*i] = prime[j];
            ++j;
        }
    }
}

void process() {
    llong res = 0;
    for(int i=1; i<=cnt; ++i)
        for(int j=i; j<=cnt && 1LL*prime[i]*prime[j] <= n; ++j) res += 1LL*prime[i]*prime[j];
    cout << res;
}

int main() {

    scanf("%d", &n); cout << n << " ";
    sieve();
    process();

    return 0;
}
    

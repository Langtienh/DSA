#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int prime[6006], f[6006], cnt = 0;
bool avail[6006];
llong n, n1;

void eratos1() {
    for(int i=2; i<=5569; ++i) {
        if (f[i] == 0) prime[++cnt] = f[i] = i;
        int j = 1;
        while (j <= cnt && prime[j] <= f[i] && prime[j] * i <= 5569) {
            f[prime[j]*i] = prime[j];
            ++j;
        }
    }
}

void eratos2() {
    n1 = max(0LL, n - 5569);
    for(llong i=2; i * i <= n; ++i)
        for(llong j = max(i*i, (n1 + i - 1) / i * i); j <= n; j+=i) avail[j - n1] = true;
}

void process() {
    for(int i=1; i<=cnt; ++i)
        if (prime[i] > n) break;
        else if (!avail[n - n1 - prime[i]] && n - prime[i] >= 2) {
            cout << prime[i] << " " << n - prime[i];
            return;
        }
    cout << -1;
}

int main() {
    scanf("%I64d", &n);
    eratos1();
    eratos2();
    process();
    return 0;
}
    

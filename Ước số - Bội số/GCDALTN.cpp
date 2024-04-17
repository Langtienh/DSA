#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int f[50006], prime[6006], cnt = 0;

void eratos() {
    for(int i=2; i<=50000; ++i) {
        if (f[i] == 0) prime[++cnt] = f[i] = i;
        int j = 1;
        while (j <= cnt && prime[j] <= f[i] && prime[j] * i <= 50000) {
            f[prime[j]*i] = prime[j];
            ++j;
        }
    }
}


llong power(int a, llong n) {
    if (n == 0) return 1;
    llong z = power(a, n>>1);
    z *= z;
    if (n & 1) z *= a;
    return z;
}

int a, b, n;

void process() {
    llong res = 1;
    for(int i=1; i<=cnt; ++i) {
        if (prime[i] > a || prime[i] > b) break;
        int cnt_a = 0, cnt_b = 0;
        while (a % prime[i] == 0) {
            ++cnt_a;
            a /= prime[i];
        }
        while (b % prime[i] == 0) {
            ++cnt_b;
            b /= prime[i];
        }
        res *= power(prime[i], min(1LL*cnt_b, 1LL*cnt_a*n));
    }
    if (a == b) res *= a;
    cout << res;
}

int main() {
    eratos();
    scanf("%d%d%d", &a, &b, &n);
    process();

    return 0;
}
    

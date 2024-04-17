#include <iostream>
#define llong long long

using namespace std;

int f[2001], n, prime[1001], cnt = 0;
llong dp[2006][21];

void eratos() {
    f[0] = -1;
    for(int i=2; i<=1120; ++i) {
        if (f[i] == 0) f[i] = prime[++cnt] = i;
        int j = 1;
        while (j <= cnt && prime[j] <= f[i] && prime[j]*i <= 1120)
            f[prime[j]*i] = prime[j], ++j;
    }
}

void init() {
    dp[0][0] = 1;
    for(int i=1; i<=cnt; ++i)
    for(int k=min(i, 14); k; --k)
    for(int j=1; j<=1120; ++j)
        if (prime[i] <= j) dp[j][k] += dp[j-prime[i]][k-1];
}

int main() {
    eratos();
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    while (n != 0 && k != 0) {
        cout << dp[n][k] << "\n";
        scanf("%d%d", &n, &k);
    }
    return 0;
}
    

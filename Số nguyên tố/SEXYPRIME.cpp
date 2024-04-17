#include <iostream>
#include <algorithm>
#define pii pair<int, int>
#define mk make_pair

using namespace std;

int f[600006], prime[80006], cnt = 0;
pii P[10006];

void eratos() {
    for(int i=2; i<=600000; ++i) {
        if (f[i] == 0) f[i] = prime[++cnt] = i;
        int j = 1;
        while (j <= cnt && prime[j] <= f[i] && prime[j] * i <= 600000) {
            f[prime[j] * i] = prime[j];
            ++j;
        }
    }
}

void init() {
    int num = 0;
    for (int i=1; i<=cnt && num < 10000; ++i)
        if (f[prime[i] + 6] == prime[i] + 6) P[++num] = mk(prime[i], prime[i]+6);
}

int main() {
    eratos(); init();

    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        cout << P[n].first << " " << P[n].second;
        putchar('\n');
    }
    return 0;
}
    

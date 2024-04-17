#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>

using namespace std;

int cnt, f[1000006], prime[80006], n, res = 0;
int **bit;

void eratos() {
    for(int i=2; i<=1000000; ++i) {
        if (f[i] == 0) prime[++cnt] = f[i] = i;
        int j = 1;
        while (j <= cnt && prime[j] <= f[i] && prime[j] * i <= 1000000) {
            f[prime[j] * i] = prime[j];
            ++j;
        }
    }
}

void init() {
    bit = new int*[cnt+1];
    for(int i=1; i<=cnt; ++i) {
        int m = 1000000 / prime[i];
        bit[i] = new int[m+1];
        for(int j=1; j<=m; ++j) bit[i][j] = 0;
    }
}

template<typename T>
bool fast_scan(T &num) {
    num = 0;
    register char c = getchar();
    while (c != '-' && (c < '0' || '9' < c)) {
        if (feof(stdin)) return false;
        c = getchar();
    }
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for(; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + (c - '0');
    if (neg) num = -num;
    return true;
}

void update(int block, int p, int val) {
    for(; p * prime[block] <= 1000000; p += (p & (-p))) bit[block][p] = max(bit[block][p], val);
}

int  query(int block, int p) {
    int ans = 0;
    for(; p>0; p -= (p & (-p))) ans = max(ans, bit[block][p]);
    return ans;
}

void update(int a, int p) {
    if (a <= 1) {
        res = max(res, 1);
        return;
    }
    int a1 = a;
    int best = 0;
    while (a > 1) {
        int tmp = f[a];
        int j = lower_bound(prime+1, prime+cnt+1, tmp) - prime, p = a1 / tmp;
        best = max(best, query(j, p-1) + 1);
        while (a % tmp == 0) a/= tmp;
    }
    a = a1; res = max(res, best);
    while (a > 1) {
        int tmp = f[a];
        int j = lower_bound(prime+1, prime+cnt+1, tmp) - prime, p = a1 / tmp;
        update(j, p, best);
        while (a % tmp == 0) a/= tmp;
    }
}

int main() {
    eratos();
    init();
    fast_scan(n);
    for(int i=1, a; i<=n; ++i) {
        fast_scan(a);
        update(a, i);
    }
    cout << res;

    return 0;
}
    

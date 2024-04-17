#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int c[100006], a[100006], cnt = 0;
int f[100006], n;
set<int> S;

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

void enter() {
    fast_scan(n); c[0] = 0, f[0] = 0;
    for(int i=1; i<=n; ++i) fast_scan(a[i]), S.insert(a[i]);
    for(set<int>::iterator i = S.begin(); i != S.end(); ++i) c[++cnt] = *i;
    for(int i=1; i<=n; ++i) a[i] = lower_bound(c+1, c+cnt+1, a[i]) - c;
}

void process() {
    int res = 1;
    for(int d=1; d<=50; ++d) {
        for(int i=1; i<=cnt; ++i) f[i] = 0;
    	for(int i=1; i<=n; ++i) {
    	    int m = c[a[i]];
            int j = lower_bound(c+1, c+cnt+1, m - d) - c;
            if (c[j] + d == m) f[a[i]] = max(f[a[i]], f[j] + 1);
            if (f[a[i]] == 0) f[a[i]] = 1;
        }
        for(int i=1; i<=cnt; ++i) res = max(res, f[i]);
    }
    cout << res;
}

int main() {
    enter();
    process();
}
    

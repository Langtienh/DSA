#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

using namespace std;

bool avail[1006];
int a[1006], n, m;

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

void check(int pos, int mod) {
    if (avail[mod]) return;
    avail[mod] = true;
    for(int i=pos+1; i<=n; ++i) check(i, (mod+a[i]) % m);
}

int main() {
    fast_scan(n), fast_scan(m);
    if (n >= m) {
    	cout << "YES";
    	return 0;
    }
    for(int i=1; i<=n; ++i) fast_scan(a[i]), a[i] %= m;
    for(int i=1; i<=n; ++i) check(i, a[i]);
    if (avail[0]) cout << "YES"; else cout << "NO";
    return 0;
}
    

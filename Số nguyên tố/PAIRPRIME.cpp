#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#define llong long long
#define pii pair<llong, llong>
#define mk make_pair

using namespace std;

pii factor(llong n) {
    llong s = 0;
    while ((n & 1) == 0) ++s, n >>= 1;
    return mk(s, n);
}

llong power(llong a, llong b, llong m) {
    llong res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }
    return res;
}

bool test(llong s, llong d, llong n, llong a) {
    if (n == a) return true;
    llong p = power(a, d, n);
    if (p == 1) return true;
    for(; s>0; --s) {
        if (p == n-1) return true;
        p = (p * p) % n;
    }
    return false;
}

bool check(llong n) {
    llong a[3] = {2, 7, 61};
    if (n < 2) return false;
    if ((n & 1) == 0) return n == 2;
    pii u = factor(n-1);
    llong s = u.first, d = u.second;
    for(int i=0; i<3; ++i)
        if (!test(s, d, n, a[i])) return false;
    return true;
}

int n, a[100006];
llong res;

int main() {
    scanf("%d", &n); a[0] = 0;
    for(int i=1; i<=n; ++i) {
        int x; scanf("%d", &x);
        a[i] = a[i-1];
        if (check(1LL*x)) {
            res += i-1;
            ++a[i];
        } else res += a[i-1];
    }
    cout << res;
}
    

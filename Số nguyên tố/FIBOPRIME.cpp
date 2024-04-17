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
    llong a[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    if (n < 2) return false;
    if ((n & 1) == 0) return n == 2;
    pii u = factor(n-1);
    llong s = u.first, d = u.second;
    for(int i=0; i<12; ++i)
        if (!test(s, d, n, a[i])) return false;
    return true;
}

llong a, b, fib[75];
int cnt[75], l = 0, r;

int main() {
    scanf("%I64d%I64d", &a, &b);
    cnt[1] = 1, cnt[2] = 2, cnt[0] = 0;
    fib[1] = 1, fib[2] = 2, r = 2;
    if (fib[2] >= a) l = 2; else if (fib[1] >= a) l = 1;
    while (fib[r] < b) {
        fib[r+1] = fib[r] + fib[r-1];
        if (fib[r+1] > b) break;
        ++r; cnt[r] += cnt[r-1];
        if (check(fib[r])) ++cnt[r];
        if (!l && fib[r] >= a) l = r;
    }
    cout << cnt[r] - cnt[l-1];
}
    

#include <iostream>
#include <algorithm>
#define llong long long
#define pii pair<llong, llong>
#define mk make_pair

using namespace std;

llong cal(llong a1, llong b1, llong m) {
    static int c[50], a[50], b[50];
    if (a1 == 0) a[0] = 1, a[1] = 0;
    else {
        a[0] =0;
        while (a1 > 0) {
            a[++a[0]] = a1 % 10;
            a1 /= 10;
        }
    }
    if (b1 == 0) b[0] = 1, b[1] = 0;
    else {
        b[0] = 0;
        while (b1 > 0) {
            b[++b[0]] = b1 % 10;
            b1 /= 10;
        }
    }
    c[0] = a[0] + b[0] - 1;
    for(int i=1; i<=c[0]+1; ++i) c[i] = 0;
    for(int i=1; i<=a[0]; ++i)
    for(int j=1; j<=b[0]; ++j) c[i+j-1] += a[i] * b[j];
    llong rem = 0;
    for(int i=1; i<=c[0]; ++i) {
        c[i] += rem;
        rem = c[i] / 10;
        c[i] %= 10;
    }
    if (rem) c[++c[0]] = rem;
    llong hold = 0;
    for(int i=c[0]; i>0; --i) hold *= 10, hold += c[i], hold %= m;
    return hold;
}

pii factor(llong n) {
    llong s = 0;
    while ((n & 1) == 0) ++s, n >>= 1;
    return mk(s, n);
}

llong power(llong a, llong b, llong m) {
    llong res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = cal(res, a, m);
        b >>= 1;
        a = cal(a, a, m);
    }
    return res;
}

bool test(llong s, llong d, llong n, llong a) {
    if (n == a) return true;
    llong p = power(a, d, n);
    if (p == 1) return true;
    for(; s>0; --s) {
        if (p == n-1) return true;
        p = cal(p, p, n);
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

int main() {
    llong n;
    scanf("%I64d", &n);
    if (check(n)) cout << "YES"; else cout << "NO";
    return 0;
}
    

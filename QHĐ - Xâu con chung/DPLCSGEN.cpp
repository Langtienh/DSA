#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define llong long long
#define ullong unsigned long long
#define pii pair<llong, llong>
#define mk make_pair

using namespace std;

int ff[1000006], prime[80006], cnt1 = 0;

void sieve() {
    ff[0] = -1;
    for(int i=2; i<=1000000; ++i) {
        if (ff[i] == 0) ff[i] = prime[++cnt1] = i;
        for(int j = 1; j<=cnt1 && prime[j]<=ff[i] && prime[j]*i<=1000000; ++j)
            ff[prime[j]*i] = prime[j];
    }
}

template<typename T>
int fast_scan(T &num) {
    num = 0;
    register char c = getchar();
    while (c != '-' && (c < '0' || '9' < c)) {
        if (feof(stdin)) return 1;
        if (c == '\n') return 2;
        c = getchar();
    }
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for(; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + (c - '0');
    if (neg) num = -num;
    if (c == '\n') return 3;
    return 0;
}

llong Find(llong P) {
    llong l = 0, r = 1e6, ans = 0;
    while (l <= r) {
        llong mid = (l+r) >> 1;
        if (mid * mid * mid <= P) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

llong Find1(llong P) {
    llong l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        llong mid = (l+r) >> 1;
        if (mid * mid <= P) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

bool check(llong P) {
    llong P1 = Find1(P);
    if (P1 * P1 == P) return true;
    P1 = Find(P);
    if (P1 * P1 * P1 == P) return ff[(int) P1] == (int) P1;
    return false;
}

llong a[2006], b[2006];
int n=0, m=0;
ullong f[2006][1006], l[2006];
set<llong> S;

void process() {
    int block = (m + 63) >> 6;
    ullong s = 1; int j = 1;
    for(int i=1; i<=m; ++i) {
        f[(int) b[i]][j] |= s;
        s <<= 1;
        if (!s) ++s, ++j;
    }
    for(int i=1; i<=n; ++i) {
        ullong b1 = 1, b2 = 0;
        for(int j=1; j<=block; ++j) {
            ullong u = l[j] | f[(int) a[i]][j];
            ullong v = u - ((l[j] << 1) | (b1+b2));
            b1 = (l[j] >> 63); b2 = (v > u);
            l[j] = u & (~v);
        }
    }
    int res = 0;
    for(int i=1; i<=block; ++i)
        for(; l[i]; ++res) l[i] &= (l[i] - 1);
    cout << res;
}

void compress() {
    vector<llong> V(S.begin(), S.end());
    for(int i=1; i<=n; ++i) {
        int j = lower_bound(V.begin(), V.end(), a[i]) - V.begin();
        a[i] = ++j;
    }
    for(int i=1; i<=m; ++i) {
        int j = lower_bound(V.begin(), V.end(), b[i]) - V.begin();
        b[i] = ++j;
    }
}

int main() {
    sieve();
    llong A, B;
    int c = fast_scan(A);
    while (c != 1 && c != 2) {
        if(check(A)) {
            a[++n] = A;
            S.insert(A);
        }
        if (c == 3) break;
        c = fast_scan(A);
    }
    c = fast_scan(B);
    while (c != 1 && c != 2) {
        if(check(B)) {
            b[++m] = B;
            S.insert(B);
        }
        if (c == 3) break;
        c = fast_scan(B);
    }
    compress();
    process();
    return 0;
}
    

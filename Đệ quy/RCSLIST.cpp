#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Data {
    llong val;
    int a[4];
} P[1009];

int n;

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

void init(int i) {
    llong tmp = P[i].val;
    P[i].a[2] = P[i].a[3] = 0;
    while (tmp % 3 == 0) ++P[i].a[3], tmp /= 3;
    while (tmp % 2 == 0) ++P[i].a[2], tmp /= 2;
}

bool cmp (const Data &A, const Data &B) {
    return A.a[2] < B.a[2] || (A.a[2] == B.a[2] && A.a[3] > B.a[3]);
}
void _sort() {
    for(int i=1; i<=n; ++i)
    for(int j=i+1; j<=n; ++j)
        if (!cmp(P[i], P[j])) swap(P[i], P[j]);
}

int main() {
    fast_scan(n);
    for(int i=1; i<=n; ++i) {
        fast_scan(P[i].val);
        init(i);
    }
    _sort();
    for(int i=1; i<=n; ++i) cout << P[i].val << " ";
    return 0;
}
    

#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, a[100006], cnt[100006];

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

int S1[100006], m;

void compress() {
    m = 0;
    sort(S1+1, S1+n+1);
    for(int i=1; i<=n; ++i) {
        int j = lower_bound(S1+1, S1+n+1, a[i]) - S1;
        a[i] = j;
    }
}

int c = 0;
pair<int, int> V[100006];

void process() {
    int l = 1, r = 0; c = 0;
    while (r < n) {
        ++r; cnt[a[r]]++;
        if (cnt[a[r]] == 2) {
            V[++c] = make_pair(l, r);
            while (l <= r) {
                cnt[a[l]]--;
                ++l;
            }
        }
    }
    while (l <= r) {
        cnt[a[l]]--;
        ++l;
    }
    if (c == 0) {
        cout << -1;
        putchar('\n');
        return;
    }
    if (V[c].second < n) V[c].second = n;
    for(int i = 1; i <= c; ++i) cout << V[i].first << " " << V[i].second << '\n';
}

int main() {

    int t; fast_scan(t);
    while (t--) {
        fast_scan(n);
        for(int i=1; i<=n; ++i) {
            fast_scan(a[i]);
            S1[i] = a[i];
        }
        compress();
        process();
    }

    return 0;
}
    

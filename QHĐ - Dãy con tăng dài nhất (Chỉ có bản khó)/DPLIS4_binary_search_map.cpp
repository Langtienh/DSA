#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

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

struct Data {
    map<int, int> M;

    bool find(int x, int y) {
        map<int, int>::iterator p = M.lower_bound(x);
        if (p == M.begin()) return false;
        --p;
        if (p->second < y) return true;
        else return false;
    }

    void add(int x, int y) {
        map<int, int>::iterator p = M.lower_bound(x), i;
        i = p;
        while (i != M.end() && i->second >= y) ++i;
        M.erase(p, i);
        M.insert(pair<int, int>(x, y));
    }
} a[100006];

int main() {
    fast_scan(n);
    int x, y, res = 1; fast_scan(x), fast_scan(y);
    a[1].add(x, y);
    for(int i=1; i<n; ++i) {
        fast_scan(x), fast_scan(y);
        int l = 0, r = res;
        while (l < r) {
            int mid = (l+r+1) >> 1;
            if (a[mid].find(x, y)) l = mid;
            else r = mid-1;
        }
        if (res <= l) res = l+1;
        a[l+1].add(x, y);
    }
    cout << res;

    return 0;
}
    

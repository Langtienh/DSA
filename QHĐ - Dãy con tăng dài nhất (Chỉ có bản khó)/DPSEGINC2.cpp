#include <iostream>
#include <algorithm>
#define pii pair<int, int>
#define mk make_pair

using namespace std;

int n, trace[200006];
int res = 0, _end = 0;
pii f[200006];

void update(int A, int p) {
     int pos = 0;
     for(int i=1; i*i <= A; ++i)
        if (A % i == 0) {
             int m = A/i;
             if(f[pos].first < f[i].first) pos = i;
             if(f[pos].first < f[m].first) pos = m;
        }
     trace[p] = f[pos].second;
     if (f[pos].first + 1 > res) {
          res = f[pos].first + 1;
          _end = p;
     }
     if (f[A].first < f[pos].first + 1) {
         f[A].first = f[pos].first + 1;
         f[A].second = p;
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

int V[200006], cnt = 0;

int main() {
    fast_scan(n);
    for(int i=1, a; i<=n; ++i) {
        fast_scan(a);
        update(a, i);
    }
    cout << res << "\n";
    while (_end != 0) {
         V[++cnt] = _end;
         _end = trace[_end];
    }
    for(int i=cnt; i>0; --i) cout << V[i] << " ";

    return 0;
}
    

#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, q;
llong S[100006];

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

llong get_ans(int u, int v, int mid) {
     return abs(S[v] - S[mid-1] - S[mid-1] + S[u-1]);
}

int main() {
    fast_scan(n), fast_scan(q);
    for(int i=1, a; i<=n; ++i) fast_scan(a), S[i] = S[i-1] + a;
    while (q--) {
        int u, v; fast_scan(u), fast_scan(v);
        int l = u+1, r = v;
        while (l+3 < r) {
             int mid1 = l + (r-l) / 3;
             int mid2 = r - (r-l) / 3;
             if (get_ans(u, v, mid1) < get_ans(u, v, mid2)) r = mid2;
             else if (get_ans(u, v, mid1) > get_ans(u, v, mid2)) l = mid1;
             else l = mid1, r = mid2;   
        }
        for(int i = l+1; i<=r; ++i) {
            if (get_ans(u, v, i) < get_ans(u, v, l)) l = i;
        } 
        cout << get_ans(u, v, l) << "\n";
    }
    
    return 0;
}
    

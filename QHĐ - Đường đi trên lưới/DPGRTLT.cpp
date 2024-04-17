#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

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

llong LA[1006][1006], LB[1006][1006], RA[1006][1006], RB[1006][1006];
int a[1006][1006], n, m;

int main() {
    fast_scan(m); fast_scan(n);
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j) {
        fast_scan(a[i][j]);
        LA[i][j] = max(LA[i-1][j], LA[i][j-1]) + a[i][j];
    }
    for(int i=1; i<=m; ++i)
    for(int j=n; j>0; --j) RA[i][j] = max(RA[i-1][j], RA[i][j+1]) + a[i][j];
    for(int i=m; i>0; --i) {
        for(int j=1; j<=n; ++j) LB[i][j] = max(LB[i+1][j], LB[i][j-1]) + a[i][j];
        for(int j=n; j>0; --j) RB[i][j] = max(RB[i+1][j], RB[i][j+1]) + a[i][j];
    }
    llong res = 0; // int mid = (1+m)/2;
    /** for(int j=2; j<n; ++j) {
        res = max(res, LA[mid-1][j] + LB[mid][j-1] + RB[mid+1][j] + RA[mid][j+1]);
        res = max(res, LA[mid][j-1] + LB[mid+1][j] + RB[mid][j+1] + RA[mid-1][j]);
    } **/
    for(int i=2; i<m; ++i)
    for(int j=2; j<n; ++j) {
        res = max(res, LA[i-1][j] + LB[i][j-1] + RB[i+1][j] + RA[i][j+1]);
        res = max(res, LA[i][j-1] + LB[i+1][j] + RB[i][j+1] + RA[i-1][j]);
    }
    cout << res;
    return 0;
}
    

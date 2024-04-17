#include <iostream>

using namespace std;

int m, n;
typedef long long llong;

llong power(int A, int N) {
    if (N == 0) return 1LL;
    llong B = power(A, N >> 1);
    B *= B;
    if (N & 1) B*=A;
    return B;
}

int main() {
    cin >> m >> n;
    unsigned long long res = 0;
    for(int i=1; i<=m; ++i) res += power(i, n);
    cout << res; 
    
    return 0;
}
    

#include <iostream>

using namespace std;

int a, b, c, d, m, n, p, q;
typedef long long llong;

llong power(int A, int N) {
    if (N == 0) return 1LL;
    llong B = power(A, N >> 1);
    B *= B;
    if (N & 1) B*=A;
    return B;
}

int main() {
    cin >> a >> b >> c >> d >> m >> n >> p >> q;
    cout << power(a, m) + power(b, n) + power(c, p) + power(d, q);
    
    return 0;
}
    

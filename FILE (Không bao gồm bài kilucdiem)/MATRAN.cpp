#include <iostream>

using namespace std;

int main() {
    (cout << fixed).precision(2);
    int n, m; scanf("%d%d", &m, &n);
    for(int i=1; i<=m; ++i, putchar('\n')) {
        double mmax = -1e9;
        for(int j=1; j<=n; ++j) {
            double a; cin >> a;
            mmax = max(mmax, a);
        }
        cout << mmax;
    }
    
    return 0;
}
    

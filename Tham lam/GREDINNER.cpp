#include <iostream>

using namespace std;

int main() {
    int n, m, res = 0;
    scanf("%d%d", &m, &n);
    for(int i=1; i<=m; ++i) {
         int mmin = 1e9;
         for(int j=1, a; j<=n; ++j) scanf("%d", &a), mmin = min(mmin, a);
         res = max(res, mmin);
    }
    cout << res;
    return 0;
}
    

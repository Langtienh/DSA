#include <iostream>

using namespace std;

long long mmin = 1e18, mmax = -1e18;
long long a[1000006];

int main() {
    int n; scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        scanf("%I64d", &a[i]);
        mmin = min(mmin, a[i]);
        mmax = max(mmax, a[i]);
    }
    for(int i=1; i<=n; ++i)
        if (a[i] == mmin) cout << mmax << " ";
        else if (a[i] == mmax) cout << mmin << " ";
        else cout << a[i] << " ";
    
    return 0;
}
    

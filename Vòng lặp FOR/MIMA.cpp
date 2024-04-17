#include <iostream>

using namespace std;

long long mmin = 1e18, mmax = -1e18;

int main() {
    int n; scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        long long a; scanf("%I64d", &a);
        mmin = min(mmin, a);
        mmax = max(mmax, a);
    }
    cout << "SO LON NHAT: " << mmax << "\nSO BE NHAT: " << mmin;
    
    return 0;
}
    

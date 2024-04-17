#include <iostream>

using namespace std;

long long mmax = -1e18;
int pos = 0;

int main() {
    int n; scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        long long a; scanf("%I64d", &a);
        if (mmax < a) mmax = a, pos = i;
    }
    cout << mmax << " " << pos;
    
    return 0;
}
    

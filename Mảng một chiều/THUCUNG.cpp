#include <iostream>

using namespace std;

int a[1000006], n, mmax = -2e9;

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]), mmax = max(mmax, a[i]);
    long long res = 0;
    for(int i=1; i<=n; ++i) res += mmax - a[i];
    
    cout << res;
    
    return 0;
}
    

#include <iostream>
#include <algorithm>

using namespace std;

int n, k, a[2006];

int main() {
    scanf("%d%d", &n, &k);
    int res = 0;
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1, greater<int>());
    for(int i=1; i<=n; i += k) res += ((a[i] - 1) << 1);
    cout << res;
    return 0;
}
    

#include <iostream>
#include <algorithm>

using namespace std;

int a[100006];

int main() {
    int n, m, s = 0; scanf("%d", &n);
    m = 4*n + n / 2 + n % 2;
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]), s += a[i];
    sort(a+1, a+n+1);
    int res = 0;
    for(int i=1; i<=n; ++i)
        if (s < m) ++res, s += 5 - a[i]; else break;  
    cout << res;
    return 0;
}
    

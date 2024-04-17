#include <iostream>
#include <algorithm>

using namespace std;

int a[100006];

int main() {
    int n, m, k, sum = 0;
    scanf("%d%d%d", &n, &k, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1, greater<int>()); a[0] = 0;
    for(int i=0; i<=m; ++i) {
        sum += a[i];
        if (sum + m - i>= k) {
            cout << i;
            return 0;
        }
    } 
    for(int i=m+1; i<=n; ++i) {
        sum += a[i] - 1;
        if (sum >= k) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
    

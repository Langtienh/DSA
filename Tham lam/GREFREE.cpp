#include <iostream>
#include <algorithm>

using namespace std;

int a[100006], n, m;
long long S = 0;

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    int mmin = n;
    for(int i=1, b; i<=m; ++i) scanf("%d", &b), mmin = min(mmin, b);
    for(int i=1; i<=n-mmin; ++i) S += a[i];
    for(int i=n-mmin+2; i<=n; ++i) S += a[i];
    cout << S;
}
    

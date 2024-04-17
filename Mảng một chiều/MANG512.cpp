#include <iostream>

using namespace std;

long double a[1000006];

int main() {
    int res = 0;
    int n; scanf("%d", &n);
    for (int i=1; i<=n; ++i) cin >> a[i];
    for (int i=1; i<=n; ++i)
       if (i == 1 && a[i] > a[i+1]) ++res;
       else if (i == n && a[i] > a[i-1]) ++res;
       else if (1 < i && i < n && a[i] > a[i+1] && a[i] > a[i-1]) ++res;
    cout << res;
    
    return 0;
}
    

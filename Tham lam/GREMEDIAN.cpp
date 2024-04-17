#include <iostream>
#include <algorithm>

using namespace std;

int a[100006], n, t;

int main() {
    scanf("%d%d", &n, &t);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    int pos = lower_bound(a+1, a+n+1, t) - a;
    if (pos == (n+1)/ 2) cout << (a[pos] != t);
    else if (pos < (n+1) / 2) {
        if (a[pos] > t) cout << abs(n - pos - pos + 2);
        else cout << abs(n - pos - pos + 1) - 1;
    } else {
        if (pos > n) cout << n+1;
        else if (a[pos] == t) cout << abs(n - pos - pos + 1);
        else cout << abs(n - pos - pos + 2) + 1;
    }
    return 0;
}
    

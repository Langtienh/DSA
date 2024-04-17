#include <iostream>
#include <algorithm>

using namespace std;

int a[100006], b[100006];

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    if (m > n) {
        cout << "NO";
        return 0;
    }
    for(int i=1; i<=m; ++i) scanf("%d", &a[i]);
    for(int j=1; j<=n; ++j) scanf("%d", &b[j]);
    sort(a+1, a+m+1); sort(b+1, b+n+1);
    for(int i=1; i<=m; ++i)
        if (a[i] <= b[i]) {
            cout << "NO";
            return 0;
        }
    cout << "YES";

    return 0;
}
    

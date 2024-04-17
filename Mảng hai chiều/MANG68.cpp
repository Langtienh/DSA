#include <iostream>
#include <algorithm>

using namespace std;

int a[1000006], n, m;

int main() {
    int l = 0; cin >> m >> n;
    for(int i=1; i<=m*n; ++i) cin >> a[i];
    sort(a+1, a+m*n+1);
    for(int i=1; i<=m; ++i, putchar('\n')) 
        for(int j=1; j<=n; ++j) cout << a[++l] << " ";
    
    return 0;
}
    

#include <iostream>
#include <algorithm>

using namespace std;

int a[1006];

int main() {
    int m, n; scanf("%d%d", &m, &n);
    for(int i=1; i<=m; ++i, putchar('\n')) {
         for(int j=1; j<=n; ++j) scanf("%d", &a[j]);
         sort(a+1, a+n+1);
         for(int j=1; j<=n; ++j) cout << a[j] << " ";     
    } 
    
    return 0;
}
    

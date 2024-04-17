#include <iostream>

using namespace std;

int a[1001][1001];

int main() {
    int m, n; scanf("%d%d", &m, &n);
    for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j) scanf("%d", &a[i][j]);
    for(int j=1; j<=n; ++j, putchar('\n')) {
        long long sum = 0;
        for(int i=1; i<=m; ++i) sum += a[i][j];
        cout << sum;
    }
    
    return 0;
}
    

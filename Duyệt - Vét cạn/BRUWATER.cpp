#include <iostream>
#define llong long long

using namespace std;

llong a[100006];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1, x, y, c; i<=m; ++i) {
        scanf("%d%d%d", &x, &y, &c);
        a[x] += c;
        a[y+1] -= c;
    }
    for (int i=1; i<=n; ++i) {
        a[i] += a[i-1];
        cout << a[i] << " ";
    }
    return 0;
}
    

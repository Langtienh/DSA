#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100006];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        cout << min(n-2, a[n-1]-1) << "\n";
    }
}
    

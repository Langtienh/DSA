#include <iostream>
#include <algorithm>

using namespace std;

long long a[100006], b[100006];

int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%I64d", &a[i]);
    for(int i=1; i<=n; ++i) scanf("%I64d", &b[i]);
    sort(b+1, b+n+1);
    for(int i=1; i<=n; ++i, putchar(' ')) {
    	int j = lower_bound(b+1, b+n+1, a[i]) - b;
    	cout << --j;
    }
    
    return 0;
}
    

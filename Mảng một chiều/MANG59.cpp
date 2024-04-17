#include <iostream>
#include <algorithm>

using namespace std;

long long a[100006];

int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%I64d", &a[i]);
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i) cout << a[i] << " ";
    
    return 0;   
}
    

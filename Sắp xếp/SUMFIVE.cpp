#include <iostream>
#include <algorithm>

using namespace std;

int a[10006];

int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1, greater<int>());
    cout << 1LL*a[1] + a[2] + a[3] + a[4] + a[5];

    return 0;
}
    

#include <iostream>
#include <algorithm>

using namespace std;

int a[100006], n, k;

int main() {
    scanf("%d%d", &n, &k); ++k;
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+2, a+n+1, greater<int>());
    long long S = 0;
    for(int i=1; i<=n; ++i)
        if (k > 0) S+=a[i], --k;
        else S -= a[i];
    cout << S;
    return 0;
}
    

#include <iostream>
#include <algorithm>

using namespace std;

int a[200006], n;

int main() {
    int mmax = 0;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    for(int i=1, r=1; i<=n; ++i) {
         while (r <=n && a[r] <= a[i]*2) ++r;
         mmax = max(mmax, r - i);
    }
    cout << mmax;
    return 0;
}
    

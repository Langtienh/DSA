#include <iostream>
#include <algorithm>

using namespace std;

int n, d, a[1006];

int main() {
    cin >> n >> d;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    int l = 1, res = 0;
    for(int i=1; i<=n; ++i) {
        while (a[i] - a[l] > d) ++l;
        res = max(res, i-l+1);
    }
    cout << n - res;
    return 0;
}
    

#include <iostream>
#include <algorithm>

using namespace std;

int n, a[4006];
bool avail[8006];

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    int res = 0;
    for(int i=1; i<=n; ++i) {
        while (avail[a[i]]) ++a[i], ++res;
        avail[a[i]] = true;
    }
    cout << res;
    return 0;
}
    

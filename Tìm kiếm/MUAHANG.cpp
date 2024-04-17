#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong S;
int n, a[100006];

bool check(int mid) {
    llong sum = 0;
    for(int i=1; i<=n; ++i) 
         if (a[i] <= mid) sum += a[i]; else sum += mid;
    return sum >= S;
}

int main() {
    scanf("%d%I64d", &n, &S);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    int l = 0, r = 1e6, ans = -1;
    while (l <= r) {
         int mid = (l+r) >> 1;
         if (check(mid)) {
             ans = mid;
             r = mid - 1;
         } else l = mid + 1;
    }
    cout << ans;
    
    return 0;
}
    

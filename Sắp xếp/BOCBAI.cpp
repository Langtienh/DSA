#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n;
int a[1000006];

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1, greater<int>());
    llong sum_Mi = 0, sum_San = a[1];
    for(int i=2; i<=n; i += 4) {
        sum_Mi += a[i] + a[i+1];
        sum_San += a[i+2] + a[i+3];
    }

    if (sum_San > sum_Mi) cout << "THANG";
    else if (sum_San < sum_Mi) cout << "THUA";
    else cout << "HOA";

    return 0;
}
    

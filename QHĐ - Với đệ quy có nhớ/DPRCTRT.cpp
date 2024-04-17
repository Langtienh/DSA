#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong dp[106][106][3];
bool avail[106][106][3];
int n, a[106];

void init() {
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j) avail[i][j][1] = avail[i][j][2] = false, dp[i][j][1] = -1e18, dp[i][j][2] = 1e18;
}

llong get_res(int i, int j, int kind) {
    if (i > j) return 0;
    if (avail[i][j][kind]) return dp[i][j][kind];
    avail[i][j][kind] = true;
    if (kind == 1) {
        llong sum = 0;
        for(int k=i; k<=j; ++k) sum += a[k], dp[i][j][1] = max(dp[i][j][1], get_res(k+1, j, 2) + sum);
        sum = 0;
        for(int k=j; k>i; --k) sum += a[k], dp[i][j][1] = max(dp[i][j][1], get_res(i, k-1, 2) + sum);
    } else {
        llong sum = 0;
        for(int k=i; k<=j; ++k) sum += a[k], dp[i][j][2] = min(dp[i][j][2], get_res(k+1, j, 1) - sum);
        sum = 0;
        for(int k=j; k>i; --k) sum += a[k], dp[i][j][2] = min(dp[i][j][2], get_res(i, k-1, 1) - sum);
    }
    return dp[i][j][kind];
}

int main() {
    scanf("%d", &n);
    while (n != 0) {
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        init();
        cout << get_res(1, n, 1) << "\n";
        scanf("%d", &n);
    }
    return 0;
}
    

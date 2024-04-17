#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong dp[5006][5006];
int a[5006], b[5006], n, m;
bool avail[5006][5006];

llong get_res(int i, int j) {
    if (i == 0) return 0;
    if (j == 0) return 1e18;
    if (avail[i][j]) return dp[i][j];
    avail[i][j] = true;
    return dp[i][j] = min(get_res(i, j-1), get_res(i-1, j-1) + abs(a[i] - b[j]));
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=m; ++i) scanf("%d", &b[i]);
    sort(a+1, a+n+1), sort(b+1, b+m+1);
    cout << get_res(n, m);
    return 0;
}
    

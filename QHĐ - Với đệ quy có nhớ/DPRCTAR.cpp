#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong dp[3006][3006];
bool avail[3006][3006];
int n, a[3006];

llong get_res(int i, int j, int kind) {
    if (i > j) return 0;
    if (avail[i][j]) return dp[i][j];
    avail[i][j] = true;
    if (kind == 1) return dp[i][j] = max(get_res(i+1, j, 2)+a[i], get_res(i, j-1, 2)+a[j]);
    else return dp[i][j] = min(get_res(i+1, j, 1) - a[i], get_res(i, j-1, 1) - a[j]);
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    cout << get_res(1, n, 1);
    return 0;
}
    

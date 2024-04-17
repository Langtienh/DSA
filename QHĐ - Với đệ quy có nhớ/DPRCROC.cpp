#include <iostream>
#include <algorithm>

using namespace std;

int S[206], T[206], n;
int dp[206][206];
bool avail[206][206];
char input[206];

void init() {
    for(int i=1; i<=n; ++i) {
        S[i] = S[i-1] + (input[i] - '0');
        T[i] = T[i-1]; if (input[i] == '0') ++T[i];
        for(int j=1; j<=n; ++j) avail[i][j] = false, dp[i][j] = 0;
    }
}

int get_res(int l, int r) {
    if (avail[l][r]) return dp[l][r];
    avail[l][r] = true;
    if (l == r) return dp[l][r] = (int) (input[l] == '1');
    dp[l][r] = (T[r] - T[l-1] < S[r] - S[l-1] ? r-l+1 : 0);
    for(int i=l; i<r; ++i) dp[l][r] = max(dp[l][r], get_res(l, i) + get_res(i+1, r));
    return dp[l][r];
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n); scanf("%s", input+1);
        init();
        cout << get_res(1, n) << "\n";
    }
    return 0;
}
    

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[206][1806], n, base = 1e9+7;
bool avail[206][1806];
char S[206];

int get_res(int pos, int pre_sum) {
    if (pos > n) return 1;
    if (avail[pos][pre_sum]) return dp[pos][pre_sum];
    avail[pos][pre_sum] = true, dp[pos][pre_sum] = 0;
    int sum = 0;
    for(int i=pos; i<=n; ++i) {
        sum += (S[i] - '0');
        if (sum >= pre_sum) dp[pos][pre_sum] = (dp[pos][pre_sum] + get_res(i+1, sum)) % base;
    }
    return dp[pos][pre_sum];
}

int main() {
    int num = 0;
    while (scanf("%s", S+1)) {
        if (S[1] == 'b') break;
        n = strlen(S+1); ++num;
        memset(avail, false, sizeof(avail));
        cout << num << ". " << get_res(1, 0) << "\n";
    }
    return 0;
}
    

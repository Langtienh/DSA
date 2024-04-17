#include <iostream>
#include <algorithm>
#include <cstring>
#define llong long long

using namespace std;

bool avail[106][106];
int k, len;
llong z, dp[106][106]; char S[106];

llong get_res(int pos, int cnt) {
    if (pos == len+1 && cnt == 0) return 0;
    if (pos == len+1) return -1;
    if (cnt == 0) return -1;
    if (avail[pos][cnt]) return dp[pos][cnt];
    llong sum = 0; avail[pos][cnt] = true; dp[pos][cnt] = -1;
    for(int i=pos; i<=len; ++i) {
        sum = sum * 10 + (S[i] - '0');
        if (sum > z) break;
        llong tmp = get_res(i+1, cnt-1);
        if (tmp != -1) dp[pos][cnt] = max(dp[pos][cnt], tmp + sum);
    }
    return dp[pos][cnt];
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d%I64d", &k, &z);
        scanf("%s", S+1); len = strlen(S+1);
        memset(avail, false, sizeof(avail));
        cout << get_res(1, k) << "\n";
    }
    return 0;
}
    

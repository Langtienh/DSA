#include <iostream>
#include <algorithm>

using namespace std;

int bit(int p) {
    int ans = 0;
    while (p > 0) {
        ans+= (p & 1);
        p >>= 1;
    }
    return ans;
}

long long S[100006], k;
int n;

int main() {
    scanf("%d%I64d", &n, &k);
    int l = 0, res = n+1;
    for(int i=1, a; i<=n; ++i) {
        scanf("%d", &a);
        S[i] += S[i-1] + bit(a);
        while (l <= i && S[i] - S[l] >= k) ++l;
        if (l > 0) res = min(res, i - l + 1); 
    }
    if (res == n+1) res = -1;
    cout << res;
    
    return 0;
}
    

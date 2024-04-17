#include <iostream>
#include <cstring>

using namespace std;

int n, k;
char S[200006], res[200006];

int main() {
    scanf("%d", &k);
    scanf("%s", S+1); res[0] = '0'; n = strlen(S+1);
    for(int i=1; i<=n; ++i)
        if (1LL*i*k == n) break;
        else if (1LL*i*k > n) {
            res[1] = '1';
            for(int i=2; i<=k; ++i) res[i] = '0';
            for(int j=1; j<=i; ++j)
                for(int kk=1; kk <= k; ++kk) cout << res[kk];
            return 0;
        }
    for(int i=1; i<=k; ++i)
        res[i] = S[i];
    int j = 0, l=1;
    bool ok = true;
    for(int i=k+1; i<=n; ++i) {
        ++j;
        if (j > k) j = 1;
        if (res[j] > S[i]) {
            ok = false;
            break;
        } else if (res[j] < S[i]) break;
    }
    if (ok) {
        int x = res[k] - '0' + 1;
        res[k] = char(x % 10 + '0'); x /= 10;
        l = k;
        while (x > 0) {
            x = res[--l] - '0' + x;
            res[l] = char(x % 10 + '0'); x /= 10;
        }
    }
    l = min(l, 1);
    for(int i=l+k; i<=n; ++i) res[i] = res[i-k];
    if (l == 0) for(int i=n+1; i<=n+k-1; ++i) res[i] = res[i - n];
    cout << res + l;
    return 0;
}
    

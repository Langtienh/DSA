#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
char S[200006], res[200006];

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", S+1); res[0] = '0';
    for(int i=1; i<=k; ++i)
        res[i] = S[i];
    int j = 0, l=1;
    for(int i=k+1; i<=n; ++i) {
        ++j;
        if (j > k) j = 1;
        if (res[j] > S[i]) break;
        if (res[j] < S[i]) {
            int x = res[k] - '0' + 1;
            res[k] = char(x % 10 + '0'); x /= 10;
            l = k;
            while (x > 0) {
                x = res[--l] - '0' + x;
                res[l] = char(x % 10 + '0'); x /= 10;
            }
            break;
        }
    }
    l = min(l, 1);
    cout << n - l + 1 << "\n";
    for(int i=l+k; i<=n; ++i) res[i] = res[i-k];
    cout << res + l;
    return 0;
}
    

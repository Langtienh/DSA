#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char S[1000006];
int n, a[256];
int f[1000006], prime[100006], cnt = 0;

void eratos() {
    f[0] = -1, f[1] = 0;
    for(int i=2; i<=n; ++i) {
        if (f[i] == 0) f[i] = prime[++cnt] = i;
        int j = 1;
        while (j <= cnt && prime[j] <= f[i] && prime[j] * i <= n) {
            f[prime[j]*i] = prime[j];
            ++j;
        }
    }
}

void process() {
    int res = 0;
    for(int i=1; i<=n; ++i) ++a[(int) S[i]];
    for(int i=0; i<256; ++i)
        if (f[a[i]] == a[i]) res += a[i];
    cout << res;
}

int main() {
    gets(S+1); n = strlen(S+1);
    eratos();
    process();
    return 0;
}
    

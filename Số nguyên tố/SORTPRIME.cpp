#include <iostream>
#include <algorithm>

using namespace std;

int n, num[3], S1;
int f[200006], prime[20006], cnt, S[200006];

void eratos() {
    for(int i=2; i<=S1; ++i) {
        S[i] = S[i-1];
        if (f[i] == 0) prime[++cnt] = f[i] = i, ++S[i];
        int j = 1;
        while (j <= cnt && prime[j] <= f[i] && prime[j] * i <= S1) {
            f[prime[j]*i] = prime[j];
            ++j;
        }
    }
}

int main() {
    scanf("%d", &n); S1 = 0;
    for(int i=1; i<=n; ++i) {
        int a; scanf("%d", &a);
        ++num[a]; S1 += a;
    }
    if (num[1] == 0) cout << 1;
    else {
        eratos();
        cout << S[S1];
    }

    return 0;
}
    

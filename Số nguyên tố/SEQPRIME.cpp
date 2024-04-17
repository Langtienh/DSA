#include <iostream>
#include <algorithm>

using namespace std;

int f[100006], prime[100006], cnt;
int n;

void eratos() {
    for(int i=2; i <= 100000; ++i) {
        if (!f[i]) f[i] = prime[++cnt] = i;
        int j = 1;
        while (j <= cnt && prime[j] <= f[i] && prime[j] * i<= 100000) {
            f[prime[j]*i] = prime[j];
            ++j;
        }
    }
}

int main() {
    eratos();
    scanf("%d", &n);
    int s;
    if (n & 1) s = 1; else s = 2;
    for (int i=s; i<=s+n-1; ++i) cout << prime[i] << " ";
    return 0;
}
    

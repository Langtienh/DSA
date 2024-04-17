#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int f[1000006], prime[100006], cnt;
llong S[1000006];

void eratos() {
    S[1] = 0;
    for(int i=2; i <= 1000000; ++i) {
    	S[i] = S[i-1];
        if (!f[i]) f[i] = prime[++cnt] = i, S[i] += i;
        int j = 1;
        while (j <= cnt && prime[j] <= f[i] && prime[j] * i<= 1000000) {
            f[prime[j]*i] = prime[j];
            ++j;
        }
    }
}

int main() {
    eratos();
    int t; scanf("%d", &t);
    while (t--) {
    	int n; scanf("%d", &n);
    	cout << S[n] << "\n";
    }
    return 0;
}
    

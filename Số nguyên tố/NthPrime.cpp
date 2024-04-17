#include <iostream>
#include <algorithm>
#include <map>
#define llong long long
#define fname "NthPRIME"

using namespace std;

int f[1500006];
int prime[120006], cnt=0;

void eratos() {
    for(int i=2; i<=1500000; ++i) {
        if (!f[i]) f[i] = prime[++cnt] = i;
        int j = 1;
        while (j <= cnt && prime[j] <= f[i] && prime[j]*i <= 1500000) {
            f[prime[j]*i] = prime[j];
            ++j;
        }
    }
}

int n;

int main() {

    eratos();
    int t, n; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        cout << prime[n];
        putchar('\n');
    }

    return 0;
}
    

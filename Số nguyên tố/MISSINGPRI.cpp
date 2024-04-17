#include <iostream>
#include <algorithm>

using namespace std;

int f[2000006], prime[200006], cnt;
int n, num[2000006];

void eratos() {
    for(int i=2; i <= 2000000; ++i) {
        if (!f[i]) f[i] = prime[++cnt] = i;
        int j = 1;
        while (j <= cnt && prime[j] <= f[i] && prime[j] * i<= 2000000) {
            f[prime[j]*i] = prime[j];
            ++j;
        }
    }
}

int main() {
    eratos();
    int mmax = 0;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
    	int a; scanf("%d", &a);
    	mmax = max(mmax, a);
    	++num[a];
    }
    for (int i=1; i<=cnt; ++i)
    	if (prime[i] > mmax) break;
    	else if (!num[prime[i]]) {
    	    cout << prime[i];
    	    return 0;
    	}
    cout << "No prime number missing!";
}
    

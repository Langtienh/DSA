#include <iostream>
#include <algorithm>
#include <map>
#define llong long long

using namespace std;

int f[10000006], n;
int prime[700006], cnt=0;
int c[9], num;

bool check(int r) {
    num = 0;
    while (r > 0) {
        c[++num] = r % 10;
        r /= 10;
    }
    int l = 1;
    while (l <= num) {
        if (c[l] != c[num]) return false;
        l++, --num;
    }
    return true;
}

void eratos() {
    for(int i=2; i<=10000000; ++i) {
        if (!f[i]) {
            f[i] = prime[++cnt] = i;
            if (i > n && check(i)) {
                cout << i;
                return;
            }
        }
        int j = 1;
        while (j <= cnt && prime[j] <= f[i] && prime[j]*i <= 10000000) {
            f[prime[j]*i] = prime[j];
            ++j;
        }
    }
}

int main() {

    scanf("%d", &n);
    eratos();

    return 0;
}
    

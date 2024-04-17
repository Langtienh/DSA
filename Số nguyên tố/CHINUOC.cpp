#include <iostream>
#include <algorithm>
#define fname "CHINUOC"

using namespace std;

int n;
int f[100006], p[100006], cnt=0;

void enter() {
    scanf("%d", &n);
}

void prime() {
    for(int i=2; i<=50000; ++i) {
        if (f[i] == 0) p[++cnt] = f[i] = i;
        int j = 1;
        while (j <= cnt && p[j] <= f[i] && p[j] * i <= 50000) {
            f[p[j]*i] = p[j];
            ++j;
        }
    }
}

bool cal(int x) {
    int ans = 1;
    while (x > 1) {
        int tmp = f[x], tmp1 = 0;
        while (x % tmp == 0) {
            tmp1++;
            x /= tmp;
        }
        ans *= (tmp1*2+1);
    }
    return ans == 9;
}

void process() {
    int res = 0;
    for(int i=1; i*i<=n; ++i)
        if (cal(i)) res++;
    cout << res;
}

int main() {

    prime();
    enter();
    process();

    return 0;
}
    

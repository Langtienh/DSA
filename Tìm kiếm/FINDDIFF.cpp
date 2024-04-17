#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong k;
int n, a[100006], f[100006], cnt = 0;

void init() {
    sort(a+1, a+n+1);
    int j = 0;
    for(int i=1; i<=n; ++i)
        if (i == n || a[i] < a[i+1]) {
            a[++cnt] = a[i];
            f[cnt] = i - j;
            j = i;
        }
}

int main() {
    scanf("%d%I64d", &n, &k);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    init(); a[0] = a[1], a[cnt+1] = a[cnt];
    llong num1 = 0, num2 = 0;
    int res = 1e9, i=0, j=cnt+1;
    while (i < j) {
        if (num1 < num2) {
            llong cost = 1LL*num1 * (1LL*a[i+1] - a[i]);
            if (cost > k) {
                int add = k / num1;
                res = a[j] - a[i] - add;
                cout << res;
                return 0;
            } else k -= cost, num1 += f[++i];
        } else {
            llong cost = 1LL*num2 * (1LL*a[j] - a[j-1]);
            if (cost > k) {
                int add = k / num2;
                res = a[j] - a[i] - add;
                cout << res;
                return 0;
            } else k -= cost, num2 += f[--j];
        }
    }
    res = 0;
    cout << res;
    return 0;
}
    

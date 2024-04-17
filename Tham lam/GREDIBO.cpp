#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int a[100006], b[100006], n, k, num1 = 0, num2 = 0, p[100006];

int main() {
    scanf("%d%d", &n, &k);
    a[0] = k;
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]), p[i] = a[i];
    llong sum = 0;
    for(int i=2; i<=n; ++i)
        if (p[i] + p[i-1] < k) p[i-1] = k - p[i] - p[i-1], sum += k - p[i];
    llong res = sum; sum = 0;
    for(int i=2; i<=n; ++i)
        if (a[i] + a[i-1] < k) sum += k - a[i-1] - a[i], a[i] = k - a[i-1];
    if (res > sum) {
        cout << sum << "\n";
        for(int i=1; i<=n; ++i) cout << a[i] << " ";
    } else {
        cout << res << "\n";
        for(int i=1; i<=n; ++i) cout << p[i] << " ";
    }
    return 0;
}
    

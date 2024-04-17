#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int a[100006], b[100006], num1 = 0, num2=0, n;

int main() {
    scanf("%d", &n);
    for(int i=1, c; i<=n; ++i) {
        scanf("%d", &c);
        if (c & 1) a[++num1] = c;
        else b[++num2] = c;
    }
    sort(a+1, a+num1+1);
    sort(b+1, b+num2+1);
    llong res = 0;
    if (num1 > num2) {
        for(int i=1; i<=num1-num2-1; ++i) res += a[i];
    } else for(int i=1; i<=num2-num1-1; ++i) res += b[i];
    cout << res;
    return 0;
}
    

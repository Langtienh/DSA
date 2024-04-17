#include <iostream>
#include <algorithm>

using namespace std;

int a[200006], b[200006], num1 = 0, num2 = 0, n;

int main() {
    scanf("%d", &n);
    for(int i=1, c; i<=n; ++i) {
        scanf("%d", &c);
        int m = sqrt(c);
        if (m * m == c) a[++num1] = c;
        else b[++num2] = min((m+1) * (m+1) - c, c - m*m);
    }
    long long res = 0;
    if (num1 == num2) cout << 0;
    else if (num1 > num2) {
        sort(a+1, a+num1+1);
        while (num1 > num2) {
            if (a[num1] == 0) res += 2;
            else res += 1;
            --num1, ++num2;
        }
        cout << res;
    } else {
        sort(b+1, b+num2+1, greater<int>());
        while (num1 < num2) res += b[num2--], ++num1;
        cout << res;
    }
    return 0;
}
    

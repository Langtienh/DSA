#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int main() {
    int n, a;
    llong L, R, LCM = 1;
    scanf("%d%I64d%I64d", &n, &L, &R);
    for(int i=1; i <= n; ++i) {
        scanf("%d", &a);
        LCM = LCM / __gcd(LCM, 1LL*a) * a;
        if (LCM > R) {
            cout << 0;
            return 0;
        }
    }
    L = (L + (LCM - 1)) / LCM;
    R = R / LCM;
    cout << R-L+1;

    return 0;
}
    

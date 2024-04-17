#include <iostream>

using namespace std;

struct BigNum {
    int a[51];
} f[206];

bool operator += (BigNum &A, const BigNum B) {
    A.a[0] = max(A.a[0], B.a[0]);
    int rem = 0;
    for(int i=1; i<=A.a[0]; ++i) {
        A.a[i] += B.a[i] + rem;
        rem = A.a[i] / 10;
        A.a[i] %= 10;
    }
    if (rem > 0) A.a[++A.a[0]] = rem;
}

int main() {
    f[0].a[0] = f[1].a[0] = f[0].a[1] = f[1].a[1] = 1;
    for(int i=2; i<=200; ++i) {
        f[i] = f[i-1];
        f[i] += f[i-2];
    }
    int t, n; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for(int i=f[n].a[0]; i; --i) cout << f[n].a[i];
        putchar('\n');
    }
    return 0;
}
    

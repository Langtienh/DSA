#include <iostream>
#include <cstring>
#define llong long long

using namespace std;

struct BigNum {
    int a[1506];
} f[5006];

char S[5006];
bool avail[100];

void operator += (BigNum &A, const BigNum B) {
    A.a[0] = max(A.a[0], B.a[0]);
    int rem = 0;
    for(int i=1; i<=A.a[0]; ++i) {
        A.a[i] += B.a[i] + rem;
        rem = A.a[i] / 10;
        A.a[i] %= 10;
    }
    if (rem) A.a[++A.a[0]] = rem;
}

int main() {
    f[0].a[0] = f[0].a[1] = f[1].a[0] = f[1].a[1] = 1;
    for(int i=1; i<=26; ++i) avail[i] = true;
    scanf("%s", S+1);
    while (true) {
        int n = strlen(S+1);
        if (n == 1 && S[1] == '0') break;
        for(int i=2; i<=n; ++i) {
            f[i].a[1] = 0; f[i].a[0] = 1;
            for(int j=2; j<=1500; ++j) f[i].a[j] = 0;
            int tmp1 = S[i] - '0', tmp2 = (S[i-1] - '0') * 10 + (S[i] - '0');
            if (avail[tmp1]) f[i] += f[i-1];
            if (tmp1 != tmp2 && avail[tmp2]) f[i] += f[i-2];
        }
        for(int i=f[n].a[0]; i; --i) cout << f[n].a[i];
        putchar('\n');
        scanf("%s", S+1);
    }
    return 0;
}
    

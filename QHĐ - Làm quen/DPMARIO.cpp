#include <iostream>
#define llong long long

using namespace std;

const llong base = 1e9;
llong f[100006];
int avail[100006];

int main() {
    int n; scanf("%d", &n);
    f[0] = 1;
    for(int i=1; i<=n; ++i) {
        scanf("%d", &avail[i]);
        if (i <= 2) {
            if (i == 1) {
                if (avail[i] == 2) f[1] = 0;
                else f[1] = 1;
            } else {
                if (avail[i] == 2) f[2] = 0;
                else if (avail[i] == 1) f[2] = f[1];
                else f[2] = f[1] + f[0];
            }
            continue;
        }
        if (avail[i] == 0) {
             f[i] = (f[i-1] + f[i-2]) % base;
             if (avail[i-3] != 1) f[i] = (f[i] + f[i-3]) % base;
        } else if (avail[i] == 1) f[i] = f[i-1] % base;
        else f[i] = 0;
    }
    f[n+1] = (f[n] + f[n-1]) % base;
    if (avail[n-2] != 1) f[n+1] = (f[n+1] + f[n-2]) % base;
    cout << f[n+1];

    return 0;
}
    

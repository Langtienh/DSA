#include <iostream>

using namespace std;

const int base = 25071987;
int f[100006], n, k;
bool avail[100006];

int main() {
    scanf("%d%d", &n, &k);
    for(int i=1, a; i<=k; ++i) {
        scanf("%d", &a); avail[a] = true;
    }
    f[0] = 0; f[1] = 1;
    for(int i=2; i<=n; ++i)
         if (avail[i]) f[i] = 0;
         else f[i] = (f[i-1] + f[i-2]) % base;
    cout << f[n];

    return 0;
}
    

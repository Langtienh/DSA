#include <iostream>
#include <cstring>

using namespace std;

char S[100006], a[100006];

int main() {
    int n; scanf("%d", &n);
    int l = n/2, r = l+1;
    int ok; if (n & 1) ok = 1; else ok = 0;
    scanf("%s", S+1);
    for(int i=1; i<=n; ++i) {
        switch (ok) {
            case 1: a[r++] = S[i]; break;
            case 0: a[l--] = S[i]; break;
        }
        ok = 1 - ok;
    }
    cout << a+1;
    return 0;
}
    

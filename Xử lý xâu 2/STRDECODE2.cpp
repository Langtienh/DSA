#include <iostream>
#include <cstring>

using namespace std;

char S[100006], a[100006];

int main() {
    int n;
    scanf("%s", S+1); n = strlen(S+1);
    int l = (n+1)/2, r = l+1;
    int ok = 0;
    for(int i=1; i<=n; ++i) {
        switch (ok) {
            case 1: a[i] = S[r++]; break;
            case 0: a[i] = S[l--]; break;
        }
        ok = 1 - ok;
    }
    cout << a+1;
    return 0;
}
    

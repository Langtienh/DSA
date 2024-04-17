#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char S[10000006];
int T[10000006];
int n, power[16];

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    power[0] = 1;
    for(int i=1; i<=9; ++i) power[i] = power[i-1] * 9;
    if (n == 1) cout << S+1;
    else {
        int mmax = 1; int p = 1;
        for(int i=1; i<=n; ++i) mmax *= (S[i] - '0');
        for(int i=1; i<=n; ++i)
            if (S[i] == 0) break;
            else {
                T[i] = S[i] - '1';
                if (T[i] > 0) p *= T[i], mmax = max(p * power[n-i], mmax), p /= T[i];
                else if (i == 1 && T[i] == 0) mmax = max(mmax, power[n-i]);
                ++T[i]; p *= T[i];
            }
        cout << mmax;
    }
    return 0;
}
    

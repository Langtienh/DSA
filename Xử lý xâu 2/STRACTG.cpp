#include <iostream>
#include <algorithm>

using namespace std;

char S[100006];
int n;

int change(char f, char t) {
    if (t > f) return min(f + 26 - t, t - f);
    else return min(t + 26 - f, f - t);
}

int main() {
    scanf("%d", &n);
    scanf("%s", S+1);
    int res = 1e9;
    for(int i=4; i<=n; ++i)
        res = min(res, change(S[i-3], 'A') + change(S[i-2], 'C') + change(S[i-1], 'T') + change(S[i], 'G'));
    cout << res;
    return 0;
}
    

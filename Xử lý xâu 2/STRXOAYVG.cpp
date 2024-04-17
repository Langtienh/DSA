#include <iostream>
#include <cstring>

using namespace std;

char S[1000006];
int res = 0, n;

int main() {
    scanf("%s", S+1); S[0] = 'a'; n = strlen(S+1);
    for(int i=1; i<=n; ++i)
        if (S[i] > S[i-1]) res += min(S[i] - S[i-1], S[i-1]+ 26 - S[i]);
        else res += min(S[i-1] - S[i], S[i]+ 26 - S[i-1]);
    cout << res;
    return 0;
}
    

#include <iostream>
#include <cstring>

using namespace std;

int num[256], n;
char S[100006];
long long res = 0;

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    for(int i=1; i<=n; ++i)
        ++num[(int) S[i]];
    for(int i=0; i<256; ++i) res += 1LL*num[i]*num[i];
    cout << res;
    return 0;
}
    

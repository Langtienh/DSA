#include <iostream>
#include <cstring>

using namespace std;

int num[256], n;
char S[100006];
long long res = 0;

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    for(int i=1; i<=n; ++i)
        res += num[(int) S[i]]++;
    cout << res;
    return 0;
}
    

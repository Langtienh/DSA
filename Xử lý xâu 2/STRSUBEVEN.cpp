
#include <iostream>
#include <cstring>

using namespace std;

long long res = 0;
char S[100006];
int n;

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    for (int i=1; i<=n; ++i)
        if ((int) S[i] % 2 == 0) res += i;
    cout << res;
    return 0;
}
    

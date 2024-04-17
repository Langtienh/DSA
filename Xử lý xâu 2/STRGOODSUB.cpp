#include <iostream>
#include <cstring>

using namespace std;

int n, k, num[26];
char S[1000006];

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", S+1);
    for (int i=1; i<=n; ++i) ++num[S[i]-'A'];
    int res = 1e9;
    for (int i=0; i<k; ++i) res = min(res, num[i]);
    cout << res*k;
    return 0;
}
    

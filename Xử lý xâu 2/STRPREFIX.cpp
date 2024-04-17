#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int a[2], n;
char S[200006];

int main() {
    cin >> n;
    scanf("%s", S+1); n = strlen(S+1); int res = 0;
    for(int i=1; i<=n; ++i)
        if (i & 1) ++a[S[i]-'a'];
        else {
            ++a[S[i]-'a'];
            if (a[1] > a[0]) S[i-1] = 'a';
            else if (a[1] < a[0]) S[i] = 'b';
            if (a[1] != a[0]) ++res, a[0] = a[1] = (a[0]+a[1])>>1;
        }
    cout << res << "\n";
    cout << S+1;
    return 0;
}
    

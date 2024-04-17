#include <iostream>
#include <cstring>

using namespace std;

int n, num[26];
char S[1000006];

int main() {
    scanf("%d", &n); n = 2*n-2;
    scanf("%s", S+1);
    int res = 0;
    for(int i=1; i<=n; ++i)
        if (i & 1) ++num[S[i]-'a'];
        else {
            if (num[S[i]-'A'] > 0) --num[S[i]-'A'];
            else ++res;
        }
    cout << res;

    return 0;
}
    

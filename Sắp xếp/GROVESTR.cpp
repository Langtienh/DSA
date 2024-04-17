#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char S[1000006];
int z[26];

int main() {
    scanf("%s", S+1); int n = strlen(S+1);
    cout << S + 1;
    for(int i=1; i<=n; ++i) ++z[S[i] - 'a'];
    int l, r; l = r = (n >> 1) + 1; ++r;
    bool left = true;
    for(int i=25; i>=0; --i)
        for(int j=1; j<=z[i]; ++j)
            if (!left) S[r] = i + 'a', ++r, left = true;
            else S[l] = i + 'a', --l, left = false;
    cout << S + 1;
}
    

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

char S[100006], S1[4];
int n, t, res[1001][26], num_s[26];

void init() {
    for(int i=1; i<=n; ++i) ++num_s[S[i]-'a'];
    for(int i=0; i<26; ++i)
    for(int l=0; l<=n-num_s[i]; ++l) {
        int f = 1, num = 0;
        for(int j=1; j<=n; ++j) {
            if (S[j] - 'a' == i) ++num;
            while (j - f + 1 > num + l) {
                if (S[f] - 'a' == i) --num;
                ++f;
            }
            res[l][i] = max(res[l][i], j - f + 1);
        }
    }
}

int main() {
    scanf("%d", &n); scanf("%s", S+1);
    init();
    scanf("%d", &t);
    while (t--) {
        int x; scanf("%d", &x);
        scanf("%s", S1+1);
        cout << res[min(x, n-num_s[S1[1]-'a'])][(int) S1[1] - 'a'] << "\n";
    }
    return 0;
}
    

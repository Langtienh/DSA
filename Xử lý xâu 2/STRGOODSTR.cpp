#include <iostream>
#include <cstring>

using namespace std;

int num1 = 0, n, m, num[26], num_block[26];
char S[100006], P[100006];
bool avail[256];

bool check() {
    int sum = 0;
    for(int i=0; i<26; ++i)
        if (avail[(int) i+'a']) {
            if (num[i] > num_block[i]) return false;
            sum += num[i];
        }
    return sum + num1 == m;
}

int main() {
    scanf("%s", S+1); n = strlen(S+1); S[0] = '/';
    scanf("%s", P+1); m = strlen(P+1);
    if (n < m) {
        cout << 0;
        return 0;
    }
    int res = 0;
    for(int i=1; i<=m; ++i) avail[(int) P[i]] = true, ++num_block[P[i]-'a'];
    for(int i=1; i<m; ++i) {
        num1 += (S[i] == '?');
        if (S[i] != '?' && avail[(int) S[i]]) ++num[S[i]-'a'];
    }
    for(int i=m; i<=n; ++i) {
        num1 += (S[i] == '?');
        if (S[i] != '?' && avail[(int) S[i]]) ++num[S[i]-'a'];
        num1 -= (S[i-m] == '?');
        if (S[i-m] != '?' && avail[(int) S[i-m]]) --num[S[i-m]-'a'];
        if (check()) ++res;
    }
    cout << res;
    return 0;
}
    

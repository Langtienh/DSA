#include <iostream>
#include <cstring>

using namespace std;

int n1, n2, next_char[10006][26];
char S1[10006], S2[1000006];
bool avail[26];

void init_next_char() {
    for(int i=n1; i>=1; --i)
    for(int j=0; j<26; ++j)
        if (S1[i]-'a'==j) next_char[i-1][j] = i; else next_char[i-1][j] = next_char[i][j];
    for(int i=0; i<26; ++i) next_char[n1][i] = next_char[0][i];
    for(int i=n1; i>=1; --i)
    for(int j=0; j<26; ++j)
        if (S1[i]-'a'==j) next_char[i-1][j] = i; else next_char[i-1][j] = next_char[i][j];
}

int main() {
    scanf("%s", S1+1); n1 = strlen(S1+1);
    scanf("%s", S2+1); n2 = strlen(S2+1);
    for(int i=1; i<=n1; ++i) avail[S1[i]-'a'] = true;
    for(int i=1; i<=n2; ++i)
        if(!avail[S2[i]-'a']) {
            cout << -1;
            return 0;
        }
    init_next_char();
    int res = 1, pos = 0;
    for(int i=1; i<=n2; ++i) {
        if (next_char[pos][S2[i]-'a'] <= pos) ++res;
        pos = next_char[pos][S2[i]-'a'];
    }
    cout << res;
    return 0;
}
    

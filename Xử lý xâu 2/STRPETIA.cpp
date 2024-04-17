#include <iostream>
#include <cstring>

using namespace std;

char S[100006], S1[100006];
bool avail[26];
int n, m, pos;

bool check() {
    if (n < m-1) return false;
    for(int i=1; i<pos; ++i)
        if (S1[i] == '?') {
            if (!avail[S[i]-'a']) return false;
        } else {
            if (S1[i] != S[i]) return false;
        }
    int l = m, r = n;
    while (l > pos) {
        if (S1[l] == '?') {
            if (!avail[S[r]-'a']) return false;
        } else {
            if (S1[l] != S[r]) return false;
        }
        --l, --r;
    }
    for(int i=pos; i<=r; ++i)
        if (avail[S[i]-'a']) return false;
    return true;
}

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    for(int i=1; i<=n; ++i) avail[S[i]-'a'] = true;
    scanf("%s", S1+1); m = strlen(S1+1);
    pos = 1;
    for(int &i=pos; i<=m; ++i)
        if (S1[i] == '*') break;
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%s", S+1); n = strlen(S+1);
        if (check()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
    

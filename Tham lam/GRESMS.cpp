#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

typedef struct Trie {
    int val;
    Trie *x[26];
} *trie;

trie New() {
    trie a;
    a = new Trie();
    a->val = 0;
    return a;
}

trie root = New();

void Insert(string s, int p) {
    int l = s.size();
    trie b = root;
    for(int i=0; i<l; ++i) {
        if (b->x[s[i]-'a'] == NULL) b->x[s[i] - 'a'] = New();
        b = b->x[s[i]-'a'];
    }
    b->val = p;
}

int Find(string s) {
    int l = s.size();
    trie b = root;
    for(int i=0; i<l; ++i) {
        if (b->x[s[i]-'a'] == NULL) return 0;
        b= b->x[s[i]-'a'];
    }
    return b->val;
}

int pos[100006], a[100006], mmin[100006];
long long res = 0;

int main() {
    int n, k, m; scanf("%d%d%d", &n, &k, &m);
    string s;
    for(int i=1; i <=n; ++i) {
        cin >> s;
        Insert(s, i);
    }
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1, x, j; i<=k; ++i) {
        scanf("%d", &x); mmin[i] = 1e9;
        while (x--) {
            scanf("%d", &j);
            pos[j] = i;
            mmin[i] = min(mmin[i], a[j]);
        }
    }
    while (m--) {
        cin >> s;
        res += mmin[pos[Find(s)]];
    }
    cout << res;

    return 0;
}
    

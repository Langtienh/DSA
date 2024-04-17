#include <iostream>
#include <cstring>

using namespace std;

char S[200006];
int num[26][200006], num1[26], n, n1;

void init() {
    for(int i=1; i<=n; ++i)
        num[S[i]-'a'][++num1[S[i]-'a']] = i;
}

bool check(int mid) {
    for(int i=0; i<26; ++i)
        if (num[mid][i] < num1[i]) return false;
    return true;
}

int b_search(char T[]) {
    for(int i=0; i<26; ++i) num1[i] = 0;
    int len = strlen(T+1);
    for(int i=1; i<=len; ++i) ++num1[T[i]-'a'];
    int ans = 0;
    for(int i=0; i<26; ++i)
        if (num1[i] > 0) {
            if (num[i][num1[i]] == 0) return -1;
            ans = max(ans, num[i][num1[i]]);
        }
    return ans;
}

int main() {
    scanf("%d", &n);
    scanf("%s", S+1);
    char S1[100006];
    init();
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%s", S1+1);
        cout << b_search(S1) << "\n";
    }
    return 0;
}
    

#include <iostream>
#include <string>
#include <set>

using namespace std;

bool avail[26];
set<string> S1;

int main() {
    int n;
    scanf("%d", &n);
    string S, T;
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<26; ++j) avail[j] = false;
        cin >> S;
        T.erase(0);
        for(int j=0; j<(int) S.length(); ++j) avail[S[j]-'a'] = true;
        for(int j=0; j<26; ++j)
            if (avail[j]) T = char(j + 'a') + T;
        S1.insert(T);
    }
    cout << S1.size();
    return 0;
}
    

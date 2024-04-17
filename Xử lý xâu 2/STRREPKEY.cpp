#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
string S1, S2;
vector<pair<char, char> > res;
int avail[26];

int main() {
    cin >> S1 >> S2; n = S1.length();
    for(int i=0; i<26; ++i) avail[i] = -1;
    for(int i=0; i < n; ++i)
        if (avail[S1[i]-'a'] < 0 && avail[S2[i]-'a'] < 0) {
            avail[S1[i]-'a'] = S2[i]-'a';
            avail[S2[i]-'a'] = S1[i]-'a';
            if (S1[i] != S2[i]) res.push_back(make_pair(S1[i], S2[i]));
        } else if (avail[S1[i]-'a'] == S2[i]-'a' && avail[S2[i]-'a'] == S1[i]-'a') continue;
        else {
            cout << -1;
            return 0;
        }
    cout << res.size() << "\n";
    for(pair<char, char> P : res) cout << P.first << " " << P.second << "\n";
    return 0;
}
    

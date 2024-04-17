#include <iostream>
#include <set>
#include <string>
#include <cstring>

using namespace std;
int s[3], n;
set<string> S;
char input[26];
string tmp;

void back_track(int cnt) {
    for(int i=0; i<2; ++i) {
        if (i == 1) {
            if (input[cnt] == '(') s[1]++;
            else s[2]++;
            if (s[1] >= s[2]) {
                tmp = tmp + input[cnt];
                if (cnt == n) {
                    if (!S.count(tmp) && s[1] == s[2]) S.insert(tmp);
                } else back_track(cnt+1);
                tmp.erase(tmp.size()-1, 1);
            }
            if (input[cnt] == '(') s[1]--;
            else s[2]--;
        } else {
            if (cnt == n) {
                if (tmp.length() > 0 && !S.count(tmp) && s[1] == s[2]) S.insert(tmp);
            } else back_track(cnt+1);
        }
    }
}
int main() {
    scanf("%s", input+1); n = strlen(input+1);
    tmp = ""; s[1] = s[2] = 0;
    back_track(1);
    cout << S.size() << "\n";
    for(set<string>::iterator i = S.begin(); i != S.end(); ++i) cout << (*i) << "\n";
    return 0;
}
    

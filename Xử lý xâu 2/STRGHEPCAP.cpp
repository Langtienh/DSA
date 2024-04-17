#include <iostream>
#include <cstring>

using namespace std;

int a[26], b[26], n;
char S[100006];

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    for(int i=1; i<=n; ++i) ++a[S[i]-'A'];
    scanf("%s", S+1); n = strlen(S+1);
    for(int i=1; i<=n; ++i) ++a[S[i]-'A'];
    scanf("%s", S+1); n = strlen(S+1);
    for(int i=1; i<=n; ++i) ++b[S[i]-'A'];
    for(int i=0; i<26; ++i)
        if (a[i] != b[i]) {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}
    

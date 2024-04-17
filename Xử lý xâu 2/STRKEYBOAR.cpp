#include <iostream>
#include <cstring>

using namespace std;

int n, a[26];
char S[26], S1[26];
char ip[100006];

int main() {
    scanf("%s", S);
    scanf("%s", S1);
    for(int i=0; i<=25; ++i) a[S[i]-'a'] = S1[i] - 'a';
    scanf("%s", ip+1); n = strlen(ip+1);
    for(int i=1; i<=n; ++i)
        if ('a' <= ip[i] && ip[i] <= 'z') cout << char(a[ip[i]-'a'] + 'a');
        else if ('A' <= ip[i] && ip[i] <= 'Z') cout << char(a[ip[i]-'A'] + 'A');
        else cout << ip[i];
    return 0;
}
    

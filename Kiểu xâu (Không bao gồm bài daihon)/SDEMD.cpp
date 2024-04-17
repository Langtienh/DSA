#include <iostream>
#include <cstring>

using namespace std;

char S[1000006];
int num[26];

int main() {
    gets(S+1); int n = strlen(S+1);
    for(int i=1; i<=n; ++i) 
        if ('A' <= S[i] && S[i] <= 'Z') ++num[S[i] - 'A'];
    for(int i=0; i<26; ++i)
        if (num[i]) cout << char(i+65) << " " << num[i] << "\n";
        
    return 0; 
}
    

#include <iostream>
#include <cstring>

using namespace std;

char S[1000006];

int main() {
    gets(S+1); int n = strlen(S+1);
    S[0] = ' ';
    for(int i=1; i<=n; ++i) {
        if ('a' <= S[i] && S[i] <= 'z' && S[i-1] == ' ') 
            S[i] = S[i] - 'a' + 'A';
        else if ('A' <= S[i] && S[i] <= 'Z' && S[i-1] != ' ') 
            S[i] = S[i] - 'A' + 'a';
        cout << S[i];
    }
    return 0;
}
    

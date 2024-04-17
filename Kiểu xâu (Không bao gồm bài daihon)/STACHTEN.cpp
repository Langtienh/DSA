#include <iostream>
#include <cstring>

using namespace std;

char S[10006];

int main() {
    gets(S+1);
    int n = strlen(S+1);
    int s = n;
    for(int i=n; i>1; --i) if (S[i-1] != ' ') --s; else break;
    for(int i=s; i<=n; ++i) cout << S[i];

    return 0;
}
    

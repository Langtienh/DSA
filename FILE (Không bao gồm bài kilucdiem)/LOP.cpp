#include <iostream>
#include <cstring>

using namespace std;

char S[10000006];

int main() {

    int n, s;
    while (gets(S+1)) {
        n = strlen(S+1);
        s = n+1;
        for(int i=n+1; i>1; --i) if (S[i-1] != ' ') --s; else break;
        for(int i=s; i<=n; ++i) 
            if (S[i] != ' ') cout << S[i]; else break;
        putchar('\n');
    }

    return 0;
}
    

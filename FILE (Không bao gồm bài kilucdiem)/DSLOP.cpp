#include <iostream>
#include <cstring>

using namespace std;

char S[10006];

int main() {
    while (gets(S+1)) {
        int n = strlen(S+1);
        for(int i=1; i<=n; ++i)
            if (S[i] == ' ') {
                if (S[i-1] != ' ') cout << S[i];
            } else cout << S[i];
        putchar('\n');
    }

    return 0;
}
    

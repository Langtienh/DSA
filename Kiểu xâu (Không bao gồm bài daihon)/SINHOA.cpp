#include <iostream>
#include <cstring>

using namespace std;

char S[1000006];

int main() {
    gets(S+1); int n = strlen(S+1);
    for(int i=1; i<=n; ++i) {
        if ('a' <= S[i] && S[i] <= 'z') S[i] = S[i] - 'a' + 'A';
        cout << S[i];
    }

    return 0;
}
    

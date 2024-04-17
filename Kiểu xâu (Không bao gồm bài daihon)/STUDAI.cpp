#include <iostream>
#include <cstring>

using namespace std;

char S[1000006];

int main() {
    gets(S+1);
    int n = strlen(S+1);
    int l = 0, r = 0;
    for(int i=1; i<=n;) {
        if (S[i] != ' ') {
            int j = i+1;
            while (j <= n && S[j] != ' ') ++j;
            if (j - i > r - l) r=j, l=i;
            i = j+1;
        } else ++i;
    }
    for(int i=l; i<r; ++i) cout << S[i];

    return 0;
}
    

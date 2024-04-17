#include <iostream>
#include <cstring>

using namespace std;

char S[1000006];
int n;

void compress() {
    scanf("%s", S+1); n = strlen(S+1);
    int j = 0;
    for(int i=1; i<=n; ++i)
        if (i == n || S[i] != S[i+1]) {
             cout << i-j;
             cout << S[i];
             j = i;
        }
}

void extract() {
    scanf("%s", S+1); n = strlen(S+1);
    for(int i=1; i<=n;)
       if ('0' <= S[i] && S[i] <= '9') {
            int j = i, l = 0;
            while ('0' <= S[j] && S[j] <= '9') {
                l *= 10;
                l += S[j++] - '0';
            }
            for(int i=1; i<=l; ++i) cout << S[j];
            i = j+1;
       } else cout << S[i++];
}

int main() {
    compress();
    cout << "\n";
    extract();
}
    

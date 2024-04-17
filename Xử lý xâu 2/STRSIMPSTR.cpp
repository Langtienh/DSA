#include <iostream>
#include <cstring>

using namespace std;

char S[1000006];
int n;

int main() {
    scanf("%s", S+1); n = strlen(S+1); S[n+1] = '0';
    for (int i=2; i<=n; ++i)
        if (S[i] == S[i-1]) {
            int j = 0;
            while (j == S[i+1] - 'a' || j == S[i-1] - 'a') j = rand() % 26;
            S[i] = char(j + 'a');
            ++i;
        }
    for(int i=1; i<=n; ++i) cout << S[i];
    return 0;
}
    

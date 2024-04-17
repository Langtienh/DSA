#include <iostream>
#include <cstring>

using namespace std;

int k;

int main() {
    char S[1000006];
    cin >> k; k %= 26;
    scanf("%s", S+1);
    for(int i=1; i<=strlen(S+1); ++i) {
        S[i] = (S[i] - 'A' + k + 'A');
        if (S[i] > 'Z') S[i] = (S[i] - 'A') - 26 + 'A';
        cout << S[i];
    }
}
    

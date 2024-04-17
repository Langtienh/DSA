#include <iostream>

using namespace std;

char S[100006];
int n, k;

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", S+1);
    for(int i=1; i<n && k > 0; ++i)
        if (S[i] == '4' && S[i+1] == '7') {
            --k;
            if (i & 1) S[i+1] = '4';
            else {
                S[i] = '7';
                if (i > 1 && S[i-1] == '4') {
                    if (k & 1) S[i] = '4';
                    else S[i] = '7';
                    break;
                }
            }
        }
    cout << S+1;
}
    

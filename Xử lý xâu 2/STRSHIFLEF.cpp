#include <iostream>
#include <cstring>

using namespace std;

char S[100006];
int n;

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    int num = 1;
    for(int i=1; i<=n && num == 1; ++i)
        if (i == n && num == 1) {
            --num;
            if (S[i] == 'a') S[i] = 'z';
            else S[i] = char(S[i] - 1);
        } else if (S[i] != 'a') {
            while (i <= n && S[i] != 'a') S[i] = char(S[i]-1), ++i;
            --num;
        }
    cout << S+1;
    return 0;
}
    

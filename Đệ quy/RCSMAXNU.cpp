#include <iostream>
#include <cstring>

using namespace std;

char S[45];
int n, mmax = 0;

int main() {
    scanf("%s", S+1); int n = strlen(S+1);
    for(int i=1; i<=n; ++i) mmax= max(mmax, (int) S[i] - '0');
    cout << mmax;
    
    return 0;
}
    

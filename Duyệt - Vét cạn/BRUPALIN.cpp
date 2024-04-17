#include <iostream>
#include <cstring>

using namespace std;

char S[1000006];

int main() {
    gets(S+1);
    int n = strlen(S+1), res = 0;
    for(int i=1; i*2 <= n; ++i)
        res += (S[i] != S[n-i+1]);
    cout << ((res == 1 || (res == 0 && (n & 1))) ? "YES" : "NO");
    return 0;
}
    

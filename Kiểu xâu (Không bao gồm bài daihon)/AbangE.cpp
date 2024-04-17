#include <iostream>
#include <cstring>

using namespace std;

bool avail[1000006];
char S[1000006];

int main() {
    gets(S+1); int n = strlen(S+1);
    for(int i=1; i<=n-2; ++i)
       if (S[i] == 'a' && S[i+1] == 'n' && S[i+2] == 'h') {
           avail[i] = true;
           i += 2;
       }
    for(int i=1; i<=n; ++i)
       if (avail[i]) {
           cout << "em";
           i += 2;
       } else cout << S[i];
    return 0;
}
    

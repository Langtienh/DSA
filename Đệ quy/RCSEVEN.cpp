#include <iostream>
#include <cstring>

using namespace std;

char S[1006];

int main() {
    int res = 0;
    scanf("%s", S+1);
    for(int i=1; i<=(int) strlen(S+1); ++i)
        if (((S[i] - '0') & 1) == 0) res += (S[i] - '0');
    cout << res;
    return 0;
}
    

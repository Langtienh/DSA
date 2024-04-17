#include <iostream>
#include <cstring>

using namespace std;

char S[1006];

int main() {
    int res = 0;
    scanf("%s", S+1);
    for(int i=1; i<=(int) strlen(S+1); ++i)
        res += ((S[i] - '0') & 1);
    cout << res;
    return 0;
}
    

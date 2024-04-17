#include <iostream>
#include <set>
#include <cstring>

using namespace std;

char S[1000006];
set<char> T;

int main() {
    scanf("%s", S+1);
    for (int i=1; i<=strlen(S+1); ++i) T.insert(S[i]);
    if ((int) T.size() % 2 == 0) cout << "GIRL";
    else cout << "NONO";
    return 0;
}
    

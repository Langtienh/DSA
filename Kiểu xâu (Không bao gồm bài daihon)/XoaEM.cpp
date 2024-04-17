#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool avail[1000006];
char S[1000006];
vector<int> V;

int main() {
    gets(S+1); int n = strlen(S+1);
    for(int i=1; i<=n; ++i)
       if (S[i] == 'e') V.push_back(i);
       else if (!V.empty() && S[i] =='m') {
           avail[i] = avail[V.back()] = true;
           V.pop_back();
       } else V.clear();
    for(int i=1; i<=n; ++i)
       if (!avail[i]) cout << S[i];
    return 0;
}
    

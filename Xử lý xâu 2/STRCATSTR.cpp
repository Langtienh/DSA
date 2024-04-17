#include <iostream>
#include <cstring>
#include <vector>
#define llong long long

using namespace std;

int n;
llong res = 0;
char S[1000006];
vector<int> test;

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    for(int i=3; i<=n; ++i)
        if (S[i-2] == 'c' && S[i-1] == 'a' && S[i] == 't') {
            test.push_back(i);
            i += 2;
        }
    test.push_back(n+1);
    for(int i=0; i<(int) test.size() - 1; ++i)
        res += (1LL*test[i]-2) * (1LL*test[i+1] - test[i]);
    cout << res;
    return 0;
}
    

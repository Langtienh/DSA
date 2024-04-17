#include <iostream>
#include <string>

using namespace std;

string S;

int main() {
    getline(cin, S);
    int res = 0;
    for(int i=0; i<(int) S.size(); ++i)
        if ('0' <= S[i] && S[i] <= '9') ++res;
    cout << res;
    
    return 0;
}
    

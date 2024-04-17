#include <iostream>
#include <string>

using namespace std;

string S;

int main() {
    getline(cin, S);
    int res = 0;
    for(int i=0; i<(int) S.size(); ++i) res += (S[i] == 'A');
    cout << res;
    
    return 0;
}
    

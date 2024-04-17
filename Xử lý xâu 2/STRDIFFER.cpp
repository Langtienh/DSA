#include <iostream>
#include <string>
#include <set>

using namespace std;

set<char> S;
string S1;

int main() {
    int n; cin >> n;
    if (n > 26) {
        cout << -1;
        return 0;
    }
    cin >> S1;
    for(int i = 0; i < n; ++i) S.insert(S1[i]);
    cout << n - S.size();
    return 0;
}
    

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S;

void check() {
    sort(S.begin(), S.end());
    for(int i=1; i<(int) S.size(); ++i)
        if (S[i] != S[i-1]+1) {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> S;
        check();
    }
    return 0;
}
    

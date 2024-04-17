#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> S;
string S1;

int main() {
    cin >> S1; int n = S1.length(), m = n;
    while (m--) {
        char tmp = S1[n-1];
        S1.erase(n-1, 1);
        S1 = tmp + S1;
        S.insert(S1);
    }
    cout << S.size();
    return 0;
}
    

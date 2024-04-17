#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string S1, S2;
    cin >> S1 >> S2;
    reverse(S1.begin(), S1.end());
    reverse(S2.begin(), S2.end());
    int res = 0;
    for(int i = 0; i < (int) min(S1.size(), S2.size()); ++i, ++res)
        if (S1[i] != S2[i]) break;
    cout << S1.size() + S2.size() - 2*res;
    return 0;
}
    

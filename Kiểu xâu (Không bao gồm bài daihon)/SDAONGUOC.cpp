#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S;

int main() {
    getline(cin, S);
    reverse(S.begin(), S.end());
    cout << S;
    
    return 0;
}
    

#include <iostream>
#include <string>

using namespace std;

string S1, S2;

int main() {
    getline(cin, S1); getline(cin, S2);
    cout << max(S1.size(), S2.size());
        
    return 0;
}
    

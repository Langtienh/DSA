#include <iostream>
#include <string>

using namespace std;

string S;

int main() {
     getline(cin, S);
     cout << S.substr(S.size() - 5, 5);
}
    

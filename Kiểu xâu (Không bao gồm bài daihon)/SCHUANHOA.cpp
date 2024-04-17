#include <iostream>
#include <string>

using namespace std;

string S;

int main() {
    getline(cin, S);
    int l = 0, r = S.size()-1;
    for(int &i=l; i<(int) S.size(); ++i) if (S[i] != ' ') break;
    for(int &i=r; i>=l; --i) if (S[i] != ' ') break;
    for(int i=l; i<=r; ++i) 
        if (S[i] == ' ') {
            if (S[i+1] != ' ') cout << S[i];
        } else cout << S[i];
        
    return 0;
}
    

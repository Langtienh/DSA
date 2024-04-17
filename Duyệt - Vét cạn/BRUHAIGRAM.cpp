#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> M;

int main() {
    int n; string S;
    cin >> n >> S;
    for(int i=1; i<n; ++i) {
        string T = "";
        T = T + S[i-1];
        T = T + S[i];
        ++M[T];
    }
    S = M.begin()->first;
    for(map<string, int>::iterator i = M.begin(); i != M.end(); ++i)
        if (i->second > M[S]) S = i->first;
    cout << S;

    return 0;
}
    

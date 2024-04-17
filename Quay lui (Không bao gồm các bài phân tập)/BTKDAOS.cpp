#include <iostream>
#include <algorithm>

using namespace std;

vector<string> V;
string S;

int main() {
    cin >> S;
    sort(S.begin(), S.end());
    V.push_back(S);
    while (next_permutation(S.begin(), S.end())) V.push_back(S);
    cout << V.size() << "\n";
    for(string e: V) cout << e << "\n";
    return 0;
}
    

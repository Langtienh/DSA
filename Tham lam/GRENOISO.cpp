#include <iostream>
#include <algorithm>

using namespace std;

string C[106];
int cnt = 0;

bool cmp(const string A, const string B) {
    return A + B > B + A;
}

int main() {
    string S;
    while(cin >> S) C[++cnt] = S;
    sort(C+1, C+cnt+1, cmp);
    for(int i=1; i<=cnt; ++i) cout << C[i];
    
    return 0;
}
    

#include <iostream>

using namespace std;

char S[11];

int main() {
    scanf("%s", S+1);
    cout << S[1];
    for (int i=2; i<=10; ++i) cout << " " << S[i];
    
    return 0; 
}
    

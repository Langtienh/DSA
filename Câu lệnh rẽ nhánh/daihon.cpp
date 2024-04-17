#include <iostream>
#include <cstring>

using namespace std;

char S1[1000006], S2[1000006];

int main() {
    gets(S1);
    gets(S2);
    if (strlen(S1) > strlen(S2)) cout << S1;
    else cout << S2;
    
    return 0;
}
    

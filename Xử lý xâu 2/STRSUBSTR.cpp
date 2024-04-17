#include <iostream>
#include <cstring>

using namespace std;

char S[1000006];
int n;

int main() {
    int i = 0;
    scanf("%s", S+1); n = strlen(S+1);
    if (n < 26) {
        cout << -1;
        return 0;
    }
    int num = 0;
    while (i < n) {
        ++i;
        if (S[i] - 'a' <= num) {
            S[i] = char(num + 'a');
            ++num;
            if (num == 26) {
                cout << S+1;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
    

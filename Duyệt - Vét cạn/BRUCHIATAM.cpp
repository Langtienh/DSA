#include <iostream>
#include <cstring>

using namespace std;

char S[108];
int n;

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    int tmp = 10;
    for(int i=1; i<=n; ++i)
        if (S[i] == '8' || S[i] == '0') tmp = min(tmp, (int) S[i] - '0');
    if (tmp < 10) {
        cout << tmp;
        return 0;
    }
    tmp = 100;
    for(int i=1; i<=n; ++i)
    for(int j=i+1; j<=n; ++j) {
        int num = (S[i] - '0') * 10 + (S[j] - '0');
        if (num % 8 == 0) tmp = min(tmp, num);
    }
    if (tmp < 100) {
        cout << tmp;
        return 0;
    }
    tmp = 1000;
    for(int i=1; i<=n; ++i)
    for(int j=i+1; j<=n; ++j)
    for(int k=j+1; k<=n; ++k) {
        int num = (S[i] - '0') * 100 + (S[j]-'0')*10 + (S[k]-'0');
        if (num % 8 == 0) tmp = min(tmp, num);
    }
    if (tmp < 1000) cout << tmp;
    else cout << "NO";
    return 0;
}
    

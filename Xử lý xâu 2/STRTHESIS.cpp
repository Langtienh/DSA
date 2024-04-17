#include <iostream>
#include <cstring>

using namespace std;

char S[1000006];
int n, num[3], num1=0, num2 = 0;

int main() {
    scanf("%d", &n);
    scanf("%s", S+1);
    for (int i=1; i<=n; ++i)
        if (S[i] == '(') ++num1;
        else if (S[i] == ')') ++num2;
    for (int i=1; i<=n; ++i) {
        if (S[i] == '(') ++num[1];
        else if (S[i] == ')') ++num[2];
        else {
            if (num1 < n/2) {
                S[i] = '(';
                ++num1;
                ++num[1];
            } else {
                S[i] = ')';
                ++num2;
                ++num[2];
            }
        }
        if (i < n && num[2] >= num[1]) {
            cout << ":(";
            return 0;
        } else if (i == n && num[2] != num[1]) {
            cout << ":(";
            return 0;
        }
    }
    cout << S+1;
    return 0;
}
    

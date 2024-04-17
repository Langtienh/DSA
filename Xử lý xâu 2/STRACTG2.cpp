#include <iostream>
#include <cstring>

using namespace std;

int num[5], n;
char S[100006];

int main() {
    cin >> n;
    if (n % 4 != 0) {
        cout << "NO";
        return 0;
    }
    int average = n / 4;
    scanf("%s", S+1);
    for(int i=1; i<=n; ++i)
        switch (S[i]) {
            case 'A' : {
                ++num[1];
                if (num[1] > average) {
                    cout << "NO";
                    return 0;
                }
                break;
            }
            case 'C' : {
                ++num[2];
                if (num[2] > average) {
                    cout << "NO";
                    return 0;
                }
                break;
            }
            case 'G' : {
                ++num[3];
                if (num[3] > average) {
                    cout << "NO";
                    return 0;
                }
                break;
            }
            case 'T' : {
                ++num[4];
                if (num[4] > average) {
                    cout << "NO";
                    return 0;
                }
                break;
            }
        }
    for(int i=1; i<=n; ++i)
        if (S[i] == '?')
            for(int j=1; j<=4; ++j) {
                if (num[j] == average) continue;
                ++num[j];
                if (j == 1) S[i] = 'A';
                if (j == 2) S[i] = 'C';
                if (j == 3) S[i] = 'G';
                if (j == 4) S[i] = 'T';
                break;
            }
    cout << S+1;
    return 0;
}
    

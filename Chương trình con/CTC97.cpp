#include <iostream>
#include <string>

using namespace std;

int main() {
    string S1, S2, S3, S4;
    cin >> S1;
    cin >> S2;
    S3 = S1, S4 = S2;
    while (S3.length() < S4.length()) S3 = '0' + S3;
    while (S4.length() < S3.length()) S4 = '0' + S4;
    for(int i=0; i<(int) S3.size(); ++i)
        if (S3[i] > S4[i]) {
             cout << S1;
             return 0;
        } else if (S3[i] < S4[i]) {
             cout << S2;
             return 0;       
        }
    cout << S1;
    return 0;
}
    

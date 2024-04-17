#include <iostream>

using namespace std;

char S[6];

void process_12() {
    int num = (S[1] - '0') * 10 + (S[2] - '0');
    if (num == 0) S[2] = '1';
    else if (num > 12) {
        if (S[2] != '0') S[1] = '0'; else S[1] = '1';
    }
    if (S[4] > '5') S[4] = '0';
    cout << S+1;
}

void process_24() {
    int num = (S[1] - '0') * 10 + (S[2] - '0');
    if (num > 23) S[1] = '0';
    if (S[4] > '5') S[4] = '0';
    cout << S+1;
}

int main() {
    int n; cin >> n;
    scanf("%s", S+1);
    if (n == 12) process_12();
    else process_24();
    return 0;
}
    

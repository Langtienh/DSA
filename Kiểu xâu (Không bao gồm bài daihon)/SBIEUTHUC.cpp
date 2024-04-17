#include <iostream>
#include <cstring>

using namespace std;

char   S[1000006];
long long sum;

int main() {
    long long a = 0;
    bool plus = true;
    gets(S+1); int n = strlen(S+1);
    for(int i=1; i<=n; ++i) 
        if ('0' <= S[i] && S[i] <= '9') {
            a *= 10; a += S[i] - '0';
        } else {
            if (plus) sum += a;
            else sum -= a;
            a = 0;
            if (S[i] == '-') plus = false;
            else plus = true;
        }
     if (plus) sum += a;
     else sum -= a;
     cout << sum;
        
     return 0;
}
    

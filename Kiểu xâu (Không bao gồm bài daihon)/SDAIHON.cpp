#include <iostream>
#include <cstring>

using namespace std;

char S[1000006], S1[1000006];

int main() {
    gets(S+1); 
    gets(S1+1);
    if (strlen(S+1) > strlen(S1+1)) {
	int n = strlen(S+1);
	for(int i=1; i<=n; ++i) {
	    if ('a' <= S[i] && S[i] <= 'z') S[i] = S[i] - 'a' + 'A';
	    cout << S[i];
	}
    } else {
  	int n = strlen(S1+1);
	for(int i=1; i<=n; ++i) {
	    if ('a' <= S1[i] && S1[i] <= 'z') S1[i] = S1[i] - 'a' + 'A';
	    cout << S1[i];
	}  
    }

    return 0;
}
    

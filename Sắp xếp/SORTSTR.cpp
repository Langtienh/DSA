#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char S[100006];

int main() {
    scanf("%s", S+1);
    sort(S+1, S+strlen(S+1)+1, [] (const char A, const char B) {
    	if ('A' <= A && A <= 'Z' && 'a' <= B && B <= 'z') return true;
    	if ('A' <= B && B <= 'Z' && 'a' <= A && A <= 'z') return false;
 	return A > B;
    });
    cout << S+1;
}
    

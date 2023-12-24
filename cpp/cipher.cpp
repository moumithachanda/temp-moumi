#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    char s[n];
    cin >> s;
    

    cout << s[0];

    for(int i=1; i+1<n ; ){
        if(s[i] == s[0] ) {
            s[0] = s[i+1];
            i++;
            cout << s[0];
        }
        else i++;
    }
    
    
}
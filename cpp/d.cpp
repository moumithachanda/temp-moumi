#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'B'){
                s[i] = '-';
                int j = i-1;
                while(j>= 0){
                    if(s[j]>='A' && s[j]<='Z'){
                        s[j] = '-';
                        break;
                    }
                    j--;
                }
            }
            if(s[i] == 'b'){
                s[i]='-';
                int j = i-1;
                while(j>=0){
                    if(s[j]>='a' && s[j]<='z'){
                        s[j] = '-';
                        break;
                    }
                    j--;
                }
            }
        }

        for(int i=0;i<s.length();i++){
            if(s[i] != '-'){
                cout << s[i]; 
            }
        }
        cout << endl;
    }
    
}
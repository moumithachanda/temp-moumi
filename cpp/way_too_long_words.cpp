#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int cnt=0;
        string :: iterator it;
        for(it = s.begin();it != s.end(); ++it){
            cnt++;
        }
        if(cnt>10){
            cout << s[0] << (cnt-2) << *(it-1) << "\n";
        }
        else{
            cout << s << "\n";
        }
    }
}
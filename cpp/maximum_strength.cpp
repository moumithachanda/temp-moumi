#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string L,R;
        cin >> L >> R;
        //padding with leading zeroes.
        if(L.length()!=R.length()){
            int k = R.length()-L.length();
            string kstr;
            for(int i=0;i<k;i++){
                kstr = '0'+kstr;
            }
            L = kstr+L;
        }
        string::iterator it1 = R.begin();
        string::iterator it2 = L.begin();
        int cnt =0;
        for(;(*it1)==(*it2);it1++,it2++){
            cnt++;
        }
        if(L==R){
            cout << 0 << "\n";
        }
        else{
            cout << (*it1)-(*it2) + 9*( R.length() - cnt -1) << "\n";
        }

        


    }
}
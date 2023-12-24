#include <iostream>

using namespace std;

int main(){
     int t;
     cin >> t;
     for(int i=0; i<t; i++){
        long long int n,k;
        cin >> n >> k;
        long long int r=0;
        long long int p;
        while(n > 0){
            
            if(n%k == 0){
                n = n/k;
                r++;

            }
            else {
                p = n%k;
                r +=p;
                n = n-p;
            }
        }
        cout << r << endl;
     }
     
}
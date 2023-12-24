#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        long int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(b>=a){
            cout << b << "\n";
        }
        else if(d>=c){
            cout << -1 << "\n";
        }
        else{
            long int k;
            if((a-b)%(c-d) == 0){
                k = (a-b)/(c-d);
                
            }
            else{
                k = ((a-b)/(c-d))+1;

            }
            cout << b+(c*k) << "\n";
            
        }
        
    }
}
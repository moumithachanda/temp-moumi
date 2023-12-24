#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n, x;
        cin >> x >> n;
        for(int i=1 ; i<=n ;i++){
            if(x%2 == 0){
                x = x- i;
            }
            else{
                x = x+i;
            }
        }
        cout << x << endl;
    }
}
#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        long long int n,k;
        cin >> n >> k;
        long long int req=0,c=1;
        while(c<k){
            c *=2;
            req++;
        }
        if(c<n){
            req += (n-c+k-1)/k; //ceiling of (n-c)/k
        }
        cout << req << "\n";  
    }
}
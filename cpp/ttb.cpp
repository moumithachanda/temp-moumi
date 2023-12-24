#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        int a[n];
        int x[q];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        
        for(int i=0;i<q;i++){
            cin >> x[i];
            int div = pow(2,x[i]);
            for(int j =0;j<n;j++){
                if(a[j]%div == 0){
                    a[j] += pow(2,x[i]-1);
                }
            }
        }
        for(int i =0;i<n-1;i++){
            cout << a[i] << " ";
        }
        cout << a[n-1] << endl;
    }
}
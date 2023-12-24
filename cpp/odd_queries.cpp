#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<q;i++){
            int l,r,k;
            cin >> l >> r >> k;
            for(int j=l-1;j<r;j++){
                a[j] = k;
            }
            int sum =0;
            for(int j=0;j<n;j++){
                sum += a[j];
            }

            if( sum % 2 == 1){
                cout << "YES"<< endl;
            }
            else cout << "NO" << endl;
        } 
    }
}
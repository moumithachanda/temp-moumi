#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int r=0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(a[i]%2 != 0) r++;
        }
        if(r%2 == 0 ) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
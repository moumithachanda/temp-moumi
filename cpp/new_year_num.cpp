#include <iostream>
using namespace std;

int main(void){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n,k;
        cin >> n;
        k = n/2020;
        if((n - (k*2020))<=k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

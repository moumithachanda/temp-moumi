#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,sum=0,k=0;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
            if(a[i]==1) k++;
        }
        sum = sum - n;
        if(n==1) cout << "NO" << endl;
        else if(k ==0) cout << "YES" << endl;
        else if(sum > k) cout << "YES" << endl;
        else cout << "NO" << endl;


    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
            b[i]=a[i];
        }

        sort(b.begin(),b.end());
        int j;
        
        for(int j=0;j<n;){
            if(a[j]%2 == b[j]%2){
                j++;
            } 
            //else break;
        }

        if(j==n){
            cout << "YES" << endl;
        }
        else cout << "NO"<< endl;
        
}
}
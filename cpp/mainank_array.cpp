#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,maxind=0,minind=0,m=0;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[maxind]<a[i]){
                maxind = i;
            } 
            if(a[minind]>a[i]){
                minind = i;
            }
        }
        if(minind==0 || maxind==n-1){
            cout << a[maxind]-a[minind] << endl;
        }
        else{
            for(int i=1;i<n;i++){
                if(m<(a[i-1]-a[i])) m = a[i-1]-a[i];
            }
            cout << m << endl;
        }
    }
}
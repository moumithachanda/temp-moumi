#include <iostream>
using namespace std;

void swap(int *a, int*b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,ans=0;
        cin >> n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
            b[i]=a[i];
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(a[j]>a[j+1]) swap(&a[j],&a[j+1]);
            }
        }
        for(int i=n-1;i>=0;){
            if(b[i]==a[i]){
                i--;
            }
            else{
                ans = a[i];
                break;
            }
        }
        cout << ans << endl;  
    }
}
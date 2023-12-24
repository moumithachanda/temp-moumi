#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        if(n == 1 ) cout << "YES" << endl;
        else{
            int p2 = 1;
        int j =0;
        int k =0;
        int flag = 1;
        while(p2 <= n){
            p2 = pow(2,j);
            //cout << " p2 = " << p2 << endl;
            if(k+1 != p2){
                if(a[k]>a[k+1] && k<n-1){
                    cout << "NO" << endl;
                    flag = 0;
                    break;
                }
                else{
                    k++;
                }
            }
            else{
                k++;
                //cout << "k=="<< k << " ";
                j++;
                //cout << "j == " <<   j << " " << endl;
            }
        }
        if(flag ==1) cout << "YES" << endl;
        }
        
    }
}
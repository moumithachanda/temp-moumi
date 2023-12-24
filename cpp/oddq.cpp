#include <iostream> 
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n , q;
        cin >> n >> q;
        vector<int> a(n);
        int sum =0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
        }

        for(int i=0;i<q;i++){
            int l,r,k;
            cin >> l >> r >> k;
            int neg =0;
            for(int j = l-1 ;j<r;j++){
                neg += a[j];
            }
            int req = sum - neg + ((r-l+1)*k);
            if(req%2 == 1) cout << " YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
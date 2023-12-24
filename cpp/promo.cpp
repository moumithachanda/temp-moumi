#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    sort(p.begin(),p.end());
    for(int i=0;i<q;i++){
        int x,y,ans=0;
        cin >> x >> y;
        for(int i=n-x; i<= n-y ; i++){
            ans = ans + p[i];
        }
        cout << ans << endl;
    }

}
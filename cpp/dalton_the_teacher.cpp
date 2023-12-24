#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int p[n],r=0;
        for(int i=1;i<=n;i++){
            cin >> p[i];
            if(p[i]==i) r++;
        }
        cout << (r/2)+(r%2) << endl;

    }
}
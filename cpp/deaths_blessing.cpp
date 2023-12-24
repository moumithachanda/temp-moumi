#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n],b[n],max=0;
        long int sum=0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum +=a[i];
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
            sum +=b[i];
            if(max < b[i]){
                max = b[i];
            }
        }
        cout << sum - max << endl;
    }
}
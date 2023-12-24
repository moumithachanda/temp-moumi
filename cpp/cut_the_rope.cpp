#include <iostream>

using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        int ab[n][2];
        for(int j=0;j<n;j++){
            cin >> ab[j][0] >> ab[j][1];
        }
        int req=0;
        for(int j=0;j<n;j++){
            if(ab[j][0] > ab[j][1]){
                req++;
            }
        }
        cout << req << "\n";
    }
}
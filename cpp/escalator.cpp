#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m, k, H;
        cin >> n >> m >> k>> H;
        int hts[n];
        for(int i=0;i<n;i++){
        cin >> hts[i];
        }
       int req=0;
        for(int i=0;i<n;i++){
        if((abs(H-hts[i])%k == 0) && (abs(H-hts[i])/k < m)&&(abs(H-hts[i])/k >0) ){
            req++;
        }
        }
        cout << req << endl;
    }   
}

#include <iostream>

using namespace std;
int main(){
    int t;
    cin >>t;
    for(int i=0;i<t;i++){
        int n,m,h;
        cin >> n >> m >> h;
        int a[n][m];
        for(int p=0;p<n;p++){
            for(int q=0; q<m ; q++){
                cin >> a[p][q];
            }
        }
        for(int j=0; j<n ; j++){
            sort(a[j]);
        }
    }

}
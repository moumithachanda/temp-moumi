#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        vector <string> v(8);
        for(int i=0;i<8;i++){
            cin >> v[i];
        }
        for(int i=0;i<8;i++){
            for(int j=0;j<8;){
                if(v[i][j] == 'R'){
                    j++;
                }
                else break;
            }
            
        }
    }
}
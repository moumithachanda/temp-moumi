#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        char s[8][8];
        vector<char> r;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin >> s[j][i];
                if(s[j][i] != '.'){
                    r.push_back(s[j][i]);
                }
            }
        }
        for(int i=0;i<r.size();i++){
            cout << r[i];
        }
        cout << endl;
    }
}
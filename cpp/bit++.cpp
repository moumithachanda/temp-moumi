#include <iostream>
using namespace std;

int main(){
    int n;
    int x=0;
    cin >> n ;
    char arr[n][3];
    for(int i=0; i<n; i++){
        for(int j=0;j<3; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0;j<3; ){
            if(arr[i][j] == 'x'|| arr[i][j] == 'X') j++; 
            else if(arr[i][j] == '+') {
                //cout << ++x << endl ; 
                ++x;
                j++;
                break;
            }
            else {
               //cout << --x << endl;
               --x;
               j++;
               break;
            } 
        }
    }

    cout << x ;
}
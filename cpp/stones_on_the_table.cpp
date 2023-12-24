#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    char a[n];
    cin >> a;
    int req=0;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            req++;
        }
    }
    cout << req;
}
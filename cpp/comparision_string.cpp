#include <iostream>
using namespace std;

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int req=1,c=1;
        for(int j=0;j<n-1;j++){
            if(s[j] != s[j+1]){
                c++;
            }
            else c=1;
            req = max(req,c);
        }
        cout << req+1 << endl;
    }
}
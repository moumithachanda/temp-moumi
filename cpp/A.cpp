#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        int p = 2;
        int a[n];
        a[0] = 2; a[1] = 3;
        cout << p << " ";
        ++p;
        cout << p;
        p++;
        for(int j=2;j<n;j++){
            while((3*p)%(a[j-1]+a[j-2]) != 0){
                p++;
            }
            a[j] = p;
            cout << " " << p;
        }
        cout << endl;
    }
}


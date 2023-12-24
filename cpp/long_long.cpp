#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        int a[n];
        for(int j=0;j<n;j++){
            cin >> a[j];
        }

        int req = 0;
        int sum =0;
        for(int j=0;j<n;j++){
            sum = sum + abs(a[j]);
        }

        for(int j=0;j<n-1;){
            if(a[j]<0){
                if(a[j+1]>0) req++;
                else if(a[j+1] ==0) j++;
                else j++;
            }
        }
        if(a[n-2]>0 && a[n-1] < 0 && req>0){
            req++;
        }
        else if(a[n-1]<0 && req==0){req++;}
        cout <<  sum << " " << req << "\n";

    }
}
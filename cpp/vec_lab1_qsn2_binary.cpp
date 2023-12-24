#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int max = INT_MIN;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    
    int l =0;
    int h = n-1;
    int mid = (h+l)/2;
    while(l<=h){
        if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){
            cout << mid << endl;
            break;

        }
        else if(v[mid]>v[mid-1] && v[mid]<v[mid+1]){
                l=mid;
                mid = (h+l)/2;
        }   
        else{
                h=mid;
                mid = (h+l)/2;
        }
    
    }
}
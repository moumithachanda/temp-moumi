#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findmin(vector<int> &v){
    int min =v[0];
    for(int i=0;i<v.size();i++){
        if(min > v[i]) min = v[i];
    }
    return min;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    //find min
    int min = findmin(v);
    int req = 0;
    
    for(int i=n-1;i>=0;i++){
        if(v[i]%2 == 1){
            req+=v[i];
        }
        else req += (v[i]-1);
    }
    if(n%2 == 1){
        if(min%2 == 0){
            req = req - min +1;
        }
        else req = req- min;
    }
    cout << req << endl;
}
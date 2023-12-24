#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool mycomp(pair<int,int> p1,pair<int,int> p2){
    return p1.first<p2.first;
}

int main(){
    int s,n;
    cin >> s >> n;
    int x[n],y[n];
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }

    //sort the array x[n] and assigned y[i]'s should go as x[i]'s.
    vector < pair<int,int> > v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(x[i],y[i]));
    }
    sort(v.begin(),v.end(),mycomp);
    int tmp = s;
    int j;
    for(j=0;j<n;j++){
        if(tmp > v[j].first){
            tmp = tmp + v[j].second;
        }
        else break;
    }
    if(j==n){
        cout << "YES" << "\n";
    }
    else cout << "NO" << "\n";
    
}
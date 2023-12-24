#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mycomp(pair<int,int> p1,pair<int,int> p2){
    return p1.first<p2.first;
};
int main(){
    int t;
    cin >> t;
    while(t--){
        int n ,k;
        cin >> n >> k;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        vector<int> b(n),req(n);
        for(int i=0;i<n;i++){
            cin >> b[i];
        }
        
        sort(b.begin(),b.end());
        
        vector < pair <int,int> > v1(n);
        for(int i=0;i<n;i++){
            v1.push_back(make_pair(a[i],i));
        }
        for(int i=0;i<n;i++){
            cout << v1[i].first << " " << v1[i].second;
        }
        cout << "\n";
        sort(v1.begin(),v1.end(),mycomp);
        for(int i=0;i<n;i++){
            cout << v1[i].first << " " << v1[i].second;
        }
        cout << "\n";
        
        for(int i=0;i<n;i++){
            req[v1[i].second] = b[i];
        }
        for(int i=0;i<n;i++){
            cout << req[i] << " ";
        }
        cout << "\n";


    }
}
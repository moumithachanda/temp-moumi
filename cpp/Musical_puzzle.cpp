#include <iostream>
#include <set>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<string> taken;
        int i=2;
        string take = "";
        take += s[0];
        take += s[1];
        taken.insert(take);
        while(i<n){
            take = "";
            take += s[i-1];
            take += s[i];
            taken.insert(take);
            i++;
        }
        cout << taken.size() << "\n";

    }
}
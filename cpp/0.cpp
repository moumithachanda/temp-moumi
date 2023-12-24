#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> g(10);
    g.push_back(1);
    g.push_back(1);
    g.push_back(1);

    cout << g.size() << " " << g.max_size()<< endl; //gives 13
    cout << g[0] << endl;
    cout << g[11] << endl;
    g.insert(g.begin(),10);

    //How to insert at mid position?
    
    cout << g[0] << endl;

}
#include <iostream>
#include <vector>
using namespace std;

void DFSHelp(int i){
    mark[i] = true;
    cout << i << " ";
    node* temp = Adjlist[i]->first;
    if(temp != nullptr){
        int n;
        for(int j=0; j< AdjList[i]->len; j++){
            n = temp->vertex;
            if(mark[n] == false){
                DFSHelp(n);
            }
            temp = temp->next;
        }
    }

}

int main(){
    vector<int> v;
    v.resize(5);
    v.push_back(20);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
}
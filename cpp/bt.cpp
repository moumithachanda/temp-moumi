#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class elem{
    private:
     int data;
     elem* left;
     elem* right;
     elem* parent;
    public:
     elem(int d = -1){
        data = d;
        left = right = parent = nullptr;
     }
     friend class bt;
     friend ostream& operator<<(ostream& os, const elem& el);
     
};

ostream& operator<<(ostream& os , const elem& el){
    cout << el.data << endl;
}

class bt{
    private:
     elem* root;
     int nnodes;
    public:
     bt(){
        root = nullptr;
        nnodes =0;
     }
     bt( elem* e){
        root = e;
        nnodes = 1;
     }
     void insertnodeLevelorder(elem* e){
        if(root == nullptr){
            root = e;
            return;
        }
        queue<elem*> q;
        q.push(root);
        while(!q.empty()){
            elem* tmp = q.front();
            q.pop();
            if(tmp->left != nullptr){
                q.push(tmp->left);
            }
            else{
                tmp->left = e;
                return;
            }

            if(tmp->right!= nullptr){
                q.push(tmp->right);
            }
            else{
                tmp->right = e;
                return;
            }
        }
     }

     void preordernonrec(){
        stack<elem *> s;
        s.push(root);
        while(!s.empty()){
            elem* tmp = s.top();
            s.pop();
            cout << *tmp;
            if(tmp->right != nullptr){
                s.push(tmp->right);
            }
            if(tmp->left != nullptr){
                s.push(tmp->left);
            }
        }
     }

};
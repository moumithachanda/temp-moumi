#include <iostream>
using namespace std;

class node{
    private:
     int data;
     node* next;

     node(int d = -1){
        data = d;
        next = nullptr;
     }

    friend class SLLv4; 
};

class SLLv4{
    private:
     node* first;
     int len;
     int getlenHelper(node*);
     void printllHelper(node*);
     void insertHelper(node*, node*);

    public:
     int getlenrec();
     void printllrec();
     void insertrec(int);
     SLLv4(){
        first = nullptr;
        len = 0;
     }
};

int SLLv4::getlenHelper(node* ptr){
    if(ptr == nullptr) return 0;
    else{
        return 1+getlenHelper(ptr->next);
    }
}

void SLLv4::printllHelper(node* ptr){
    if(ptr == nullptr){
        return;
    }
    else{
        cout << ptr->data << " ";
        printllHelper(ptr->next);
    }
    //cout << endl;
}

void SLLv4::insertHelper(node* ptr,node* newnode){
    if(ptr->next == nullptr){
        ptr->next = newnode;
        len++;
        return;
    }
    else{
        insertHelper(ptr->next,newnode);
    }
}

void SLLv4::insertrec(int d){
    node* newnode = new node(d);
    if(first==nullptr){
        first = newnode;
        len++;
        return;
    }
    else{
      insertHelper(first,newnode);
    }
}

void SLLv4::printllrec(){
    printllHelper(first);
}
int SLLv4::getlenrec(){
    return getlenHelper(first);
}

int main(){
    SLLv4 linkedlist;
    linkedlist.insertrec(10);
    linkedlist.insertrec(12);
    linkedlist.insertrec(14);
    linkedlist.insertrec(16);
    cout << linkedlist.getlenrec() << endl;
    linkedlist.printllrec();
}
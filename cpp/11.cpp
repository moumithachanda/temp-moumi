#include <iostream>
using namespace std;

class node{
   public: 
    int data;
    node* next;

    node(){
        data = -1;
        next = NULL;
    } 
    node(int d){
        data = d;
        next = nullptr;
    }
};

class linkedlist{
   private: 
    node* first;
    node* first1;
    int len;
   public:
    linkedlist(){
        first = nullptr;
        len =0;
    } 

    void getdata(int d){
        node* toaddnode = new node(d);
        if(first == nullptr){
            first = toaddnode;
            first1=first;
            len++;
        }
        else{
            node* tmp = first;
            while(tmp->next != NULL){
                tmp = tmp->next;
            }
            tmp->next = toaddnode;
            len++;
        }
    }
    bool check_x(int x){
        node* tmp = first;
        while(tmp != nullptr){
            if(tmp->data == x){
                return true;
            }
            tmp= tmp->next;
        }
        return false;
    }

    void print_ll();
    void deletex(int);
    void delete_lastx(int);
    void delete_allx(int);
    void insert_x_after_y(int,int);
    void recprint();
    void rev_recprint();

};

void linkedlist::rev_recprint(){
    
    node* tmp = first1;
    
    if(tmp == nullptr){
        cout <<  endl;
        return;
    }
    else{
        first1 = first1->next;
        recprint();
    }
    cout << tmp->data << " ";
    //cout << tmp->data  << endl;
}

void linkedlist::recprint(){
    //node* tmp = first;
    //in this code first is changing so better to use another variable.
    if(first== nullptr){
        cout <<  endl;
        return;
    }
    else{
        cout << first->data << " ";
        first = first->next;
        recprint();
    }
    //cout << tmp->data  << endl;
}

void linkedlist::print_ll(){
    node* tmp = first;
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void linkedlist::deletex(int x){
    node* tmp = first;
    if(tmp->data == x){
        first = tmp->next;
        delete tmp;
        len--;
    }
    else{
        while((tmp->next)->data != x){
            tmp = tmp->next;
        }
        node* tmp1 = tmp->next;
        tmp->next = tmp->next->next;
        delete tmp1;
        len--;
    }
}

void linkedlist::delete_lastx(int x){
    
    if(len==0) return;
    node* tmp = first;
    node* tobedeleted = nullptr;
    node* occured = nullptr;

    for(int i=0;i<len-1;i++){
        if(tmp->next->data == x){
            occured = tmp;
        }
        tmp = tmp->next;
    }
    if(occured == nullptr){
        if(first->data ==  x){
            tobedeleted = first;
            first = first->next;
            delete tobedeleted;
            len--;
        }
        return;
    }
    else{
          tobedeleted = occured->next;
          occured->next = occured->next->next;
          delete tobedeleted;
          len--;
    }
}


void linkedlist::delete_allx(int x){
    //if x is present delete its first occurence.
    while(check_x(x)){
        deletex(x);
    }
}

void linkedlist::insert_x_after_y(int x, int y){
    node* toaddnode = new node(x);
    node* tmp = first;
    if(!check_x(y)){
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = toaddnode;
        len++;
    }
    else{
        while(tmp->data != y){
            tmp= tmp->next;
        }
        node* tmp1 = tmp->next;
        tmp->next = toaddnode;
        tmp->next->next = tmp1;
        len++;
    }
}

int main(){
    linkedlist ll;
    ll.getdata(10);
    ll.getdata(12);
    ll.getdata(14);
    ll.getdata(16);
    ll.getdata(12);
    ll.getdata(18);
    ll.print_ll();
    ll.insert_x_after_y(5,20);
    ll.print_ll();
    //ll.rev_recprint();
    ll.recprint();

}
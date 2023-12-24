#include <iostream>
using namespace std;

class node{
    public:
     int data;
     node* next;
     
     node(int t){
        data = t;
        next = nullptr;
     }
};

class linkedlist{
    private:
     node* head;
     int len;

    public:
     linkedlist(){
        head = nullptr;
        len = 0;
     }

     void insertnode(int t){
        node* toaddnode = new node(t);

        if(head == nullptr){
            head = toaddnode;
        }
        else{
            node* tmp = head;
            while(tmp->next!=nullptr){
                tmp = tmp->next;
            }
            tmp->next = toaddnode;
        }
        len++;
     }
     void print(){
        node* tmp = head;
        while(tmp != nullptr){
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
     }
     int num_ll(){
        int x =0;
        x = head->data;
        node* tmp = head->next;
        while(tmp != nullptr){
            x = 10*x + (tmp->data);
            tmp = tmp->next;
        }
        return x;
     }
};

int main(){
    linkedlist l;
    //l.initialise();
    l.insertnode(9);
    l.insertnode(1);
    l.insertnode(5);
    l.insertnode(2);
    cout << l.num_ll()<< endl;


}
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

     void initialise(){
        head = nullptr;
        len = 0;
     };

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
};

int main(){
    linkedlist l;
    //l.initialise();
    l.insertnode(120);
    l.insertnode(130);
    l.insertnode(150);
    l.print();


}
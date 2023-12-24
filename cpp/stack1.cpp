#include <iostream>
using namespace std;

class elem{
    private:
     int data;
     elem* next;
    public:
     elem(int i = -1){
        data = i;
        next = nullptr;
     }

    friend class stackl;
};

class stackl{
    private:
     elem* top;
    public:
     stackl(){
        top = nullptr;
     }
     void push(elem& E){
        elem* tmp = &E;
        tmp->next = top;
        top = tmp;
     }

     void pop(){
        elem* tmp = top;
        top = top->next;
        delete tmp;
     }

     bool isempty(){
        return (top == nullptr);
     }   
};
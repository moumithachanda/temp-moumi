#include <iostream>

using namespace std;

class elem{
    private:
     int data;
     char c;
    public:
     elem(int d = -1, char b = 'a'){
        data = d;
        c = b;
     }
    friend class stack;
};
class stack{
    private:
     elem *estack;
     int top;
     int capacity;
    public:
     stack(int cap = 16){
        estack = new elem[cap];
        top = -1;
        capacity = 0;
     }

     bool isempty(){
        return (top == -1);
     }
     bool isfull(){
        return (top = capacity-1);
     }
     void push(const elem & e){
        assert(!isfull());
        top++;
        estack[top] = e;
     }
     void pop(){
        assert(!isempty());
        estack[top].~elem();
        top--;
     }
     int len(){
        return top+1;
     }
     const elem& top(){
        return estack[top];
     }

};

int main(){
    stack s1;
    s1.push(elem(10,'a'));
    s1.push(elem(11,'b'));
    

}
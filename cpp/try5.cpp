#include <iostream>
using namespace std;

void fun(int *p){
    *p = 20;
}

void fun2(int& p){
    p = 30;
}

int main(){
    int x;
    fun(&x);
    cout << " value of x : " << x << endl;
    fun2(x);
    cout << " value of x : " << x << " " << endl;
    
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class nodeSLL {
private:
  unsigned int data;
  int balance;
  nodeSLL *next;

  nodeSLL(int d = -1) {
    data = d;
    balance = 1000;
    next = nullptr;
  }

  friend class SLL;
  friend class DLL;
};

class SLL {
private:
  nodeSLL *first;
  nodeSLL *last;
  int len;

public:
  SLL() {
    first = nullptr;
    last = nullptr;
    len = 0;
  }

  void insertnodeSLL(unsigned int d) {
    nodeSLL *toaddnodeSLL = new nodeSLL(d);
    if (first == nullptr) {
      first = toaddnodeSLL;
      last = toaddnodeSLL;
      len++;
    } else {
      last->next = toaddnodeSLL;
      last = last->next;
      len++;
    }
  }

  void mduty(){
    nodeSLL* tmp = first;
    nodeSLL* tmp1;
    int maxbal = tmp->balance;
    while(tmp != nullptr){
        if(maxbal < tmp->balance){
            maxbal = tmp->balance;
            tmp1 = tmp;
        }
    }
    cout << tmp1->data << endl;
  }

  int getlenSLL() { return len; }

  bool isvalidacc(int x) {
    nodeSLL *tmp = first;
    while (tmp != nullptr) {
      if (tmp->data == x) {
        return 1;
      }
      tmp = tmp->next;
    }
    return 0;
  }

  nodeSLL *searchacc(unsigned int a) {
    nodeSLL *tmp = first;
    while (tmp != nullptr) {
      if (tmp->data == a) {
        return tmp;
      }
      tmp = tmp->next;
    }
    return nullptr;
  }

  void printSLL() {
    nodeSLL *tmp = first;
    while (tmp != nullptr) {
      cout << tmp->data << " " << tmp->balance << endl;
      tmp = tmp->next;
    }
  }

  void gduty(int x){
    int count = 0;
    nodeSLL* tmp = first;
    while(tmp != nullptr){
        if(tmp->balance >= x){
            count++;
        }
        tmp = tmp->next;
    }
    cout << count << endl;
  }
  void vduty(int x){
    nodeSLL* tmp = searchacc(x);
    cout << tmp->balance << endl;
  }

};

class nodeDLL {
private:
  int accno;
  char c;
  int amt;
  nodeDLL *prev;
  nodeDLL *nxt;

public:
  nodeDLL(int p = -1, char q = 'x', int r = -1) {
    accno = p;
    c = q;
    amt = r;
    prev = nullptr;
    nxt = nullptr;
  }

  friend class DLL;
};

class DLL {
private:
  nodeDLL *head;
  nodeDLL *tail;
  nodeDLL *cursor;
  int l;

public:
  DLL() {
    head = new nodeDLL();
    tail = new nodeDLL();
    head->nxt = tail;
    tail->prev = head;
    cursor = head;
    l = 0;
  }

  void insertnodeDLL(int a, char b, int d) {
    nodeDLL *toaddnodeDLL = new nodeDLL(a, b, d);
    toaddnodeDLL->nxt = tail;
    toaddnodeDLL->prev = tail->prev;
    (tail->prev)->nxt = toaddnodeDLL;
    tail->prev = toaddnodeDLL;
    l++;
  }


  int getl() { return l; }

  //   int getreq() {
  //     int req = 0;
  //     while (cursor != tail) {
  //       req++;
  //     }
  //     return req;
  //   }

  void printDLL() {
    nodeDLL *tmp = head->nxt;
    while (tmp != tail) {
      cout << tmp->accno << " " << tmp->c << " " << tmp->amt << endl;
      tmp = tmp->nxt;
    }
  }
  void funf(int x, SLL &s) {
    if (cursor == head) {
      cursor = cursor->nxt;
    }
    nodeSLL *req;
    for (int i = 0; i < x; i++) {
      if (cursor != tail) {
        // cursor = cursor->nxt;
        req = s.searchacc(cursor->accno);
        if (cursor->c == 'D') {
          req->balance += cursor->amt;
        } else {
          req->balance -= cursor->amt;
        }
        cursor = cursor->nxt;
      } else
        break;
    }
  }
  void maketrans(nodeDLL* given,SLL & s){
        nodeSLL *req;
        req = s.searchacc(given->accno);
        if (cursor->c == 'D') {
          req->balance += cursor->amt;
        } else {
          req->balance -= cursor->amt;
        }
  }

  void rduty(int y, SLL& s){
    nodeSLL* req;
    for(int i=0;i<y;i++){
        if(cursor != head){
            req = s.searchacc(cursor->accno);
            if (cursor->c == 'D') {
              req->balance -= cursor->amt;
            } else {
              req->balance += cursor->amt;
            }
        cursor = cursor->prev;
        }
        else{
          cursor = head->nxt;
          break;
        }
    }
  }
   
  void insertafter_k(int k, int p, char q, int r, SLL s){
    nodeDLL* tmp = head;
    l++;
    if(k>l-1 || s.isvalidacc(p)==false)
    return;
    for(int i=0;i<k;i++){
        tmp = tmp->nxt;
    }
    nodeDLL* ins = new nodeDLL(p,q,r);
    ins->nxt = tmp->nxt;
    ins->prev = tmp;
    (tmp->nxt)->prev = ins;
    tmp->nxt = ins;
  }

  //   void cduty(SLL &s) {
  //     nodeSLL *req;
  //     cursor = cursor->nxt;
  //     while (cursor != tail) {
  //       req = s.searchacc(cursor->accno);
  //       if (req != nullptr) {
  //         if (cursor->c == 'D') {
  //           req->balance += cursor->amt;
  //         } else {
  //           req->balance -= cursor->amt;
  //         }
  //         cursor = cursor->nxt;
  //       }
  //     }
  //   }
};

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int C;
  cin >> C;
  SLL accounts;
  for (int i = 0; i < C; i++) {
    unsigned int accno;
    cin >> accno;
    accounts.insertnodeSLL(accno);
  }

  //accounts.printSLL();
  //cout << endl;

  int N;
  cin >> N;
  DLL transactions;
  for (int i = 0; i < N; i++) {
    int accno;
    char c;
    int amt;
    cin >> accno >> c >> amt;
    if (accounts.isvalidacc(accno)) {
      transactions.insertnodeDLL(accno, c, amt);
    }
  }

  //transactions.printDLL();
  //cout << endl;

  string s;
  cin >> s;
  while (s != "END") {
    if (s == "F") {
      int X;
      cin >> X;
      transactions.funf(X, accounts);
    }
    else if(s == " R"){
       int Y;
       cin >> Y;
       transactions.rduty(Y,accounts);
    }
    else if(s == "I"){
        int p; char q; int r;
        cin >> p >> q >> r;
        int K;
        cin >> K;
        for(int i=0;i<K;i++){
            transactions.insertafter_k(K,p,q,r,accounts);
        }
    }
    else if(s == "G"){
        int x;
        cin >> x;
        accounts.gduty(x);
    }
    else if(s == "V"){
        int x;
        cin >> x;
        accounts.vduty(x);
    }
    else if(s == "M"){
        accounts.mduty();
    }
    cin >> s;
  }
  //accounts.printSLL();
  //cout << endl;
  return 0;
}
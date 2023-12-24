#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
    // Implement your functions here
    private:
     string name;
     int identifier;
     int coursesdone;
     float cgpa;
    public:
     Student(string str1, int id1, int done1, float cg1){
         name = str1; identifier = id1; coursesdone = done1; cgpa= cg1;
     }
     Student(string str1, int id1){
         name = str1; identifier= id1; coursesdone=0; cgpa =0;
     }
     void PrintStudent(){
         cout << "ID: " << identifier << " Name: " << name << " Courses Done: " << coursesdone << " CGPA: " << cgpa << endl;
     }
     string GetName(){
         return name;
     }
     int GetID(){
         return identifier;
     }
     int GetDone(){
         return coursesdone;
     }
     float GetCGPA(){
         return cgpa;
     }
     bool AboveCGPACutoff(double cutOffValue){
          if(cgpa > cutOffValue) return 1;
          else return 0;
      }
     void changeid(){
          identifier = -1;
      }
      /*void getdata(){
        cin >> name >> identifier >> coursesdone >> cgpa;
      }*/ 
      // we can use this in general but idk why isn't it working here?
      
};

int main(){
    // take N as input and then take N student record as input here
    int N,M;
    cin >> N;
    vector<Student> s(N);
    for(int i=0;i<N;i++){
        //s[i].getdata(); This is wrong if we did not mention the sizeof vector.
        // we need to do pushback by introducing another object of same class and then we need to push_back that object to this object
        string n;
        int id;
        int cd;
        float cg;
        cin >> n >> id >> cd >> cg;
        Student a(n,id,cd,cg);
        s.push_back(a);
    }
    
    // take number of queries as input here (M) and then process each query one by one
    cin >> M;
    for(int i=0;i<M;i++){
        int query;
        cin >> query;
        if(query==1){
            float y;
            cin >> y;
            for(int j=0;j<N;j++){
                if(s[j].GetCGPA() > y && s[j].GetID()!= -1){
                    cout << s[j].GetName() << " ";
                }
            }
            cout << endl;
        }
        else {
            int deleteid;
            cin >> deleteid;
            for(int j=0;j<N;j++){
                if(s[j].GetID() == deleteid){
                    s[j].changeid();
                    break;
                }
            }  
        }
    }

      // print all student record after processing all queries
    for(int i=0;i<N;i++){
        if(s[i].GetID() != -1){
            s[i].PrintStudent();
        }
    }
}
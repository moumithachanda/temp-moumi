#include <iostream>
#include <vector>
using namespace std;

void call(vector<char> x){
    if(x.size()==1){
        cout << "0" << x[0];
    }
    else{
        cout << x[0] << x[1];
    }
}
void call2(vector<char> x){
    if(x.size()==1){
      cout <<"000"<< x[0];
    }
    else if(x.size()==2){
        cout << "00" << x[0]<<x[1];
    }
    else if(x.size()==3){
        cout << "0" <<x[0] << x[1]<<x[2];
    }
    else {
        cout << x[0]<<x[1]<<x[2]<<x[3];
    }
}

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        vector<char> s1,s2,s3;
        int j,k=0;
        int p=0;
        if(s[1]=='.'||s[2]=='.'){
            k=1;
        }
        if(s[1] == '.' || s[1] == '/'){
            s1.push_back(s[0]);
            p++;
        }
        else{
            s1.push_back(s[0]);
            s1.push_back(s[1]);
            p+=2;
        }

        if(p==1){
          if(s[3] == '.' || s[3] == '/'){
            s2.push_back(s[2]);
            j=3;
          }
          else{
            s2.push_back(s[2]);
            s2.push_back(s[3]);
            j=4;

          }
        }
        else{
            if(s[4] == '.' || s[4] == '/'){
              s2.push_back(s[3]);
              j=4;
             }
          else{
            s2.push_back(s[3]);
            s2.push_back(s[4]);
            j=5;
          }
        }
        for(int i=j+1;i<s.length();i++){
            s3.push_back(s[i]);
        }
        
        if(k == 1){
            call(s1);
            cout << '.';
            call(s2);
            cout << '.';
            call2(s3);

            cout << " ";

            call(s2);
            cout << '/';
            call(s1);
            cout << '/';
            call2(s3);
        }
        else{
            call(s2);
            cout << '.';
            call(s1);
            cout << '.';
            call2(s3);

            cout << " ";

            call(s1);
            cout << '/';
            call(s2);
            cout << '/';
            call2(s3);
          }
        cout << endl;
        
    }
}

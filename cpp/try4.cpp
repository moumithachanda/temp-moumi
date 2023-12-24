#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector<int> v1(5,2);
    vector<int> v2(4,3);
    v1.swap(v2);
    for(int i=0;i<4;i++){
        cout << v2[i] << " ";
    }

}
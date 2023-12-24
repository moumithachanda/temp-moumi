#include <iostream>

using namespace std;
void bubble_sort(int arr[], int n) {  
  int i, j;  
  for (i = 0; i < n - 1; i++) {  
    for (j = 0; j < n - i - 1; j++) {  
      if (arr[j] > arr[j + 1]) {  
        int temp = arr[j];  
        arr[j] = arr[j + 1];  
        arr[j + 1] = temp;  
      }  
    }  
  }  
}  
int main(){
    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        int n;
        int sum =0;
        cin >> n;
        int a[n];
        for(int j=0;j<n;j++){
            cin >> a[j];
        }
        bubble_sort(a, n); 
        
        for(int p=0;p<(n/2);p++){
            sum = sum + a[n-1-p]-a[p];
        }
        cout << sum << "\n";
    }
}
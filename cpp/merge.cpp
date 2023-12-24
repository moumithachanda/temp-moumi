#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVec(vector<int> A)
{
  int i, j;
  int n = A.size();
  
  for (int i : A)
    {
      cout << i << " ";
    }

  cout << endl;

}

void MergeA(vector<int> &A, int L, int Mid, int R)
{
  vector<int>C;
  int i, j, k;
  int size = R - L + 1;
  C.resize(size);
  i = L; j = Mid + 1; k = 0;
  while ((i <= Mid) && (j <= R))
    {
      if (A[i] < A[j])
	{
	  C[k] = A[i]; k++; i++;
	}
      else
	{
	  C[k] = A[j]; k++; j++;
	}
    }
  if (i > Mid)
    {
      for (int m = j; m <= R; m++, k++){C[k] = A[m];}
    }
  if (j > R)
    {
      for (int m = i; m <= Mid; m++, k++){C[k] = A[m];}
    }
  for (int n = 0; n < size; n++){A[n+L] = C[n];}
  cout << endl;
  return;
}


void MergeSort(vector<int> &A, int L, int R)
{
  int c;
  if (R == L) return;
  if (R == L+1)
    {
      if (A[R] < A[L])
	{
	  int t = A[R];
	  A[R] = A[L];
	  A[L] = t;
	}
      return;
    }
  int Mid = (L + R) / 2;
  MergeSort(A, L, Mid);
  MergeSort(A, Mid+1, R);
  MergeA(A, L, Mid, R);
}

int CheckSort(const vector<int> &A)
{
  for (int j = 1; j < A.size(); j++)
    {
      if (A[j] < A[j-1])
	return 0;
    }
  return 1;
}

int main()
{
  // Use  -std=gnu++11 with g++
  //  vector<int> A1 = { 1, 4, 7, 9, 10, 2, 3, 5, 6, 8};

  std::srand(std::time(nullptr));
  cout << "Enter vector size: ";
  int N;
  cin >> N;
  vector<int> A1(N);
  
  for (int p = 0; p < N; p++)
    {
      A1[p] = rand()%10000;
    }

  cout << "Before sorting" << endl;
  PrintVec(A1);

  MergeSort(A1, 0, N - 1);

  cout << "After sorting" << endl;
  PrintVec(A1);
  cout << endl;
  
  cout << "Sorted correctly: " << CheckSort(A1) << endl;

}
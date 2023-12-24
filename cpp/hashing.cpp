#include<iostream>
#include<vector>
#include<string>
using namespace std;

enum status {ACTIVE, DELETED, EMPTY};

long int HashFn1(long int x, long int M)
{
  //  return (x^2 + 3*x) % M;
  return (x) % M;
}

long int HashFn2(long int x, long int R)
{
  return (R - (x % R));
}

// Warning: Does not correctly check if x is present in table
// Duplicate addition of x to Table is possible
// Ideally, Search for x and if not found, then insert x.

/*so it is correct to put a proper search first first in the delete insertion code. */

bool HT_insert(vector<long int> &HashTable,
	    vector<status> &StatusTable,
	    long int x, long int M,
	    long int& probecount) 
{
  long int pos, newpos;
  int i;

  pos = HashFn1(x, M);
  i = 0;
  
  while (i < M)
    {
      newpos = (pos + i) % M;
      //      newpos = (pos + i*i) % M; Quadratic
      //      newpos = (pos + i* HashFn2(x)) % M; Double

      if ((StatusTable[newpos] == ACTIVE) &&
	  (HashTable[newpos] == x))
      {
	// Entry already exists; new entry is ignored.
	cout << "Key: " << x << " already exists in position: " << newpos
	       << endl;

	return false;
      }

      if (StatusTable[newpos] != ACTIVE)
	{
	  //	  probecount += (i+1);
	  HashTable[newpos] = x;
	  StatusTable[newpos] = ACTIVE;
	  cout << "Key: " << x << " Orig. pos: " << pos <<
	    " Inserted into position: " << newpos
	       << " i: " << i << endl;

	  return true;
	}
      else
	{
	  i++;
	  cout << "i: " << i << endl;
	}
    }

  if (i == M)
    {
      return false;
    }
      
}

bool HT_delete(vector<long int> &HashTable,
	    vector<status> &StatusTable,
	    long int x, long int M,
	    long int& probecount) 
{
  long int pos, newpos;
  int i;

  pos = HashFn1(x, M);
  i = 0;
  
  while (i < M)
    {
      newpos = (pos + i) % M;

      if ((StatusTable[newpos] == ACTIVE) &&
	  (HashTable[newpos] == x))
	{
	  HashTable[newpos] = -1;
	  StatusTable[newpos] = DELETED;
	  cout << "Key: " << x << " Orig. pos: " << pos <<
	    " Deleted from position: " << newpos
	       << " i: " << i << endl;

	  return true;
	}
      else
	{
	  i++;
	  cout << "i: " << i << endl;
	}
    }

  if (i == M)
    {
      return false;
    }
      
}

// Add HT_search to locate key x in the HT and return true or false
// (present or absent)  
// Ideally, one would return the corresponding value in the key-value pair.
// bool HT_search ....
int HT_search(vector<long int> &HashTable,
	    vector<status> &StatusTable,
	    long int x, long int M){
            long int pos,newpos;
            pos = HashFn1(x,M);
            int i=0;
            while(i<M){
                newpos = (pos+i)%M;
                if(HashTable[newpos]==x && StatusTable[newpos]==ACTIVE){
                    return newpos;
                }
                if(StatusTable[newpos] == EMPTY){
                    return -1;
                }
                else{
                    i++;
                }
            }
            return -1;
        }

//Print contents
void HT_print(vector<long int> &HashTable,
	      vector<status> &StatusTable)
{
  for (int i = 0; i < HashTable.size(); i++)
    {
      if (StatusTable[i] == ACTIVE)
	cout << "Table position: " << i << " Key stored: " <<
	  HashTable[i] << endl;
    }
  
}

int main()
{
  
  long int n, M, pos;

  vector<long int> HashTable;
  vector<status> StatusTable;
    
  cout << "Enter n M: ";
  
  cin >> n;
  cin >> M;
  HashTable.resize(M, -1);
  StatusTable.resize(M, EMPTY);

  long int totprobe_linear_ins = 0;
  long int totprobe_linear_del = 0;
  int inpcount = 0;
  long int x;
  char c;

  cout << "Enter I/D/P/E <num>: ";
  cin >> c;
  cin >> x;
  int done = 0;
  while (!done)
    {
      switch (c)
	{
	case 'I':
	  if (HT_insert(HashTable, StatusTable, x, M, totprobe_linear_ins)
	      == false)
	    {
	      cout << "Hash Table unable to insert: " << x << endl;
	    }
	  break;

	case 'D':
	  if (HT_delete(HashTable, StatusTable, x, M, totprobe_linear_del)
	      == false)
	    {
	      cout << "Hash Table unable to find and delete: " << x << endl;
	    }
	  break;

	// case 'S':
	//   if (HT_search(HashTable, StatusTable, x, M, totprobe_linear_del)
	//       == false)
	//     {
	//       cout << "Hash Table unable to locate: " << x << endl;
	//     }
	//   break;

	case 'P':
	  HT_print(HashTable, StatusTable);
	  break;
	  
	case 'E':
	  done = 1;
	  break;
	}
      
      if (!done) {
	cout << "Enter I/D/P/E <num>: ";
	cin >> c;
	cin >> x;
	
      } 
    } // End While
}
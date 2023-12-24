#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Example container (vector of vectors)
    vector< vector<int> > adj = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Iterate over elements in the container using a range-based for loop
    cout << adj.size() << endl;
    for (int t = 0; t < adj.size(); ++t) {
        for (int j : adj[t]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

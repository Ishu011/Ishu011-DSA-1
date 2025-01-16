#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Create a new matrix to store rotated result
    vector<vector<int>> rotated(n, vector<int>(n, 0)); 
    
    // Loop through the original matrix and place elements in the rotated matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - i - 1] = matrix[i][j]; // Rotate the element
        }
    }

    return rotated; // Return the rotated matrix
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> rotated = rotate(arr);

    // Output the rotated matrix
    cout << "Rotated Image:" << endl;
    for (int i = 0; i < rotated.size(); i++) {
        for (int j = 0; j < rotated[0].size(); j++) {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

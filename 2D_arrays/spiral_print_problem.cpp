#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int n = matrix.size(); 
    int m = matrix[0].size(); // Corrected matrix size extraction
    int startingrow = 0; // Added missing semicolon
    int startingcol = 0;
    int endingrow = n - 1; // Added missing '='
    int endingcol = m - 1;
    int total = n * m;
    int count = 0;

    while (count < total) {
        // for starting row
        for (int i = startingcol; count < total && i <= endingcol; i++) {
            ans.push_back(matrix[startingrow][i]);
            count++;
        }
        startingrow++;

        // for ending column
        for (int i = startingrow; count < total && i <= endingrow; i++) {
            ans.push_back(matrix[i][endingcol]);
            count++;
        }
        endingcol--;

        // for ending row
        for (int i = endingcol; count < total && i >= startingcol; i--) {
            ans.push_back(matrix[endingrow][i]);
            count++;
        }
        endingrow--;

        // for starting column
        for (int i = endingrow; count < total && i >= startingrow; i--) {
            ans.push_back(matrix[i][startingcol]);
            count++;
        }
        startingcol++;
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = spiralOrder(matrix);
    
    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
/*
dry run 
matrix = [
    [ 1,  2,  3],
    [ 4,  5,  6],
    [ 7,  8,  9]
]
Initialize variables:

n = 3 (number of rows)
m = 3 (number of columns)
startingrow = 0
startingcol = 0
endingrow = 2
endingcol = 2
total = 9
count = 0
ans = [] (empty vector to store the spiral order)
While count < total (initially 0 < 9), perform the following steps:

a. Traverse the top row from startingcol to endingcol:

i = 0, startingrow = 0
Push matrix[0][0] (1) to ans, increment count
Push matrix[0][1] (2) to ans, increment count
Push matrix[0][2] (3) to ans, increment count
Increment startingrow to 1
b. Traverse the right column from startingrow to endingrow:

i = 1, endingcol = 2
Push matrix[1][2] (6) to ans, increment count
Push matrix[2][2] (9) to ans, increment count
Decrement endingcol to 1
c. Traverse the bottom row from endingcol to startingcol:

i = 1, startingrow = 1
Push matrix[2][1] (8) to ans, increment count
Push matrix[2][0] (7) to ans, increment count
Decrement endingrow to 0
d. Traverse the left column from endingrow to startingrow:

i = 0, startingcol = 0
Push matrix[1][0] (4) to ans, increment count
Push matrix[0][0] (1) to ans, increment count
Increment startingcol to 1
e. Traverse the top row from startingcol to endingcol:

This step is skipped since startingrow > endingrow.
The count is now 9, which is equal to total, so the while loop stops.

The ans vector will contain the correct spiral order: [1, 2, 3, 6, 9, 8, 7, 4, 5]. 
*/
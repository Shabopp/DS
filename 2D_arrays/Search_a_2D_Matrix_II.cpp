#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int rowindex = 0;
    int colindex = m - 1;

    while (rowindex < n && colindex >= 0) {
        int element = matrix[rowindex][colindex];
        if (element == target) {
            return true;
        } else if (element > target) {
            colindex--;
        } else {
            rowindex++;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    int target = 16;

    bool result = searchMatrix(matrix, target);

    if (result) {
        cout << "Target found in the matrix." << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}
/*
dry run
matrix:
1, 3, 5, 7
10, 11, 16, 20
23, 30, 34, 50
target: 16
Initialization:

n (number of rows): 3
m (number of columns): 4
rowindex: 0
colindex: 3
Iteration 1:

element at matrix[0][3] is 7
Since 7 < 16, update rowindex = 1
Iteration 2:

element at matrix[1][3] is 20
Since 20 > 16, update colindex = 2
Iteration 3:

element at matrix[1][2] is 16
Since 16 == 16, return true
Final result: Target found in the matrix.

Output:

Copy code
Target found in the matrix.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int row = matrix.size();
    for(int i = 0; i < row; i++) {
        for(int j = 0; j <= i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i = 0; i < row; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9}};

    cout << "Original Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    rotate(matrix);

    cout << "Rotated Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
Given matrix:

Copy code
1 2 3
4 5 6
7 8 9
First Loop (swap operations):

i = 0, j = 0: Swapping matrix[0][0] and matrix[0][0] (no change)
i = 1, j = 0: Swapping matrix[1][0] and matrix[0][1]
i = 1, j = 1: Swapping matrix[1][1] and matrix[1][1] (no change)
i = 2, j = 0: Swapping matrix[2][0] and matrix[0][2]
i = 2, j = 1: Swapping matrix[2][1] and matrix[1][2]
i = 2, j = 2: Swapping matrix[2][2] and matrix[2][2] (no change)
Matrix after first loop:

Copy code
1 4 7
2 5 8
3 6 9
Second Loop (reverse operations):

i = 0: Reversing the first row (7 4 1)
i = 1: Reversing the second row (8 5 2)
i = 2: Reversing the third row (9 6 3)
Final rotated matrix after both loops:

Copy code
7 4 1
8 5 2
9 6 3
So, the original matrix has been rotated clockwise by 90 degrees, resulting in the rotated matrix as shown above.
*/
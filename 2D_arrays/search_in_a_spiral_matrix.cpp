#include <bits/stdc++.h> 
#include<iostream>
using namespace std;
#include<vector>

int findKthElement(vector<vector<int>> matrix, int k) {
    vector<int> ans;
    int m = matrix.size();
    int n = matrix[0].size();
    int j = 0;

    int rowStart = 0;
    int rowEnd = m-1;
    int colStart = 0;
    int colEnd = n-1;

    while(j < k){
        // Traverse from left to right along the top row.
        for(int i=colStart; j<k && i<=colEnd; i++){
            ans.push_back(matrix[rowStart][i]);
            j++;
        }
        rowStart++;

        // Traverse from top to bottom along the rightmost column.
        for(int i=rowStart; j<k && i<=rowEnd; i++){
            ans.push_back(matrix[i][colEnd]);
            j++;
        }
        colEnd--;

        // Traverse from right to left along the bottom row.
        for(int i=colEnd; j<k && i>=colStart; i--){
            ans.push_back(matrix[rowEnd][i]);
            j++;
        }
        rowEnd--;

        // Traverse from bottom to top along the leftmost column.
        for(int i=rowEnd; j<k && i>=rowStart; i--){
            ans.push_back(matrix[i][colStart]);
            j++;
        }
        colStart++;
    }
    return ans[j-1]; // Return the kth element (0-based index).
}
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int k = 5; // We want to find the 5th element.

    int result = findKthElement(matrix, k);

    cout << "The " << k << "th element in the matrix is: " << result << endl;

    return 0;
}
/*
Dry Run:

Let's dry run the code with a sample input:

vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
int k = 5; // We want to find the 5th element.

findKthElement(matrix, k);
Initialize variables:

m = 3 (number of rows)
n = 3 (number of columns)
rowStart = 0, rowEnd = 2, colStart = 0, colEnd = 2
j = 0, ans is initially empty.
Loop iterations:

1st iteration: Traverse top row (1 2 3). j becomes 3.
2nd iteration: Traverse rightmost column (6 9). j becomes 5.
The loop exits because j is now equal to k.
Return ans[5-1], which is ans[4], and ans is {1, 2, 3, 6, 9}. So, the function returns 9, which is the 5th element.

The function returns 9 as the output, which is the 5th element in the given matrix in a spiral order.
*/




#include <iostream>
#include <vector>

using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nrows, int mcols) {
    vector<int> ans;
    for (int col = 0; col < mcols; col++) {
        if (col & 1) {
            // Odd column
            for (int rows = nrows - 1; rows >= 0; rows--) {
                ans.push_back(arr[rows][col]);
            }
        } else {
            // Even column
            for (int rows = 0; rows < nrows; rows++) {
                ans.push_back(arr[rows][col]);
            }
        }
    }
    return ans;
}

int main() {
    int nrows, mcols;
    cout << "Enter the number of rows: ";
    cin >> nrows;
    cout << "Enter the number of columns: ";
    cin >> mcols;

    vector<vector<int>> arr(nrows, vector<int>(mcols));
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < mcols; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> result = wavePrint(arr, nrows, mcols);

    cout << "Wave-printed elements:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

/*dry run
Enter the matrix elements:
1 2 3 4
5 6 7 8
9 10 11 12

Now, the wavePrint function is called with the provided matrix and dimensions.

Inside wavePrint function:

mcols is 4 (number of columns).

Starting from column 0 (even column):

Row 0: Push 1 to the answer vector.
Row 1: Push 5 to the answer vector.
Row 2: Push 9 to the answer vector.
Moving to column 1 (odd column):

Row 2: Push 10 to the answer vector.
Row 1: Push 6 to the answer vector.
Row 0: Push 2 to the answer vector.
Moving to column 2 (even column):

Row 0: Push 3 to the answer vector.
Row 1: Push 7 to the answer vector.
Row 2: Push 11 to the answer vector.
Moving to column 3 (odd column):

Row 2: Push 12 to the answer vector.
Row 1: Push 8 to the answer vector.
Row 0: Push 4 to the answer vector.
The wavePrint function returns the answer vector containing the wave-printed elements.

Back in the main function, the wave-printed elements are printed:
Wave-printed elements:
1 5 9 10 6 2 3 7 11 12 8 4 
*/
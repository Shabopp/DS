#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateArray(vector<int>& arr, int n) {
    int temp = arr[0];
    for(int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    return arr;
}

int main() {
    // Sample array and rotation count
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Rotate the array
    arr = rotateArray(arr, n);

    cout << "Rotated Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
Now, let's do a dry run of the code:

We define a vector arr containing {1, 2, 3, 4, 5} and set n to 5.

We print the original array: 1 2 3 4 5

We call the rotateArray function with arr and n as arguments.

Inside rotateArray, we store the first element (1) in temp.

We then loop from i = 1 to i = 4 (as n is 5), and in each iteration, we move the element at index i to the left by one position. This effectively shifts all elements to the left by one position.

After the loop, we assign the temp value (which was 1) to the last element, making the array {2, 3, 4, 5, 1}.

We return the modified arr vector.

In the main function, we print the rotated array: 2 3 4 5 1

So, the code rotates the array to the left by one position.
*/
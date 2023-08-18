#include <iostream>
#include <vector>
using namespace std;

vector<int> rotatebyk(vector<int> &arr, int n, int k) {
    vector<int> temp(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        temp[(i + k) % arr.size()] = arr[i];
    }
    return temp;
}

void printVector(const vector<int> &arr) {
    for (const int &element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    arr = rotatebyk(arr, 6, 2);
    printVector(arr);
    return 0;
}

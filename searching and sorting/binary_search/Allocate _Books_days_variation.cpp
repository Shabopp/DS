#include <iostream>
using namespace std;

bool ispossible(int arr[], int n, int m, int mid) {
    int dayscount = 1;
    int timespend = 0;
    for (int i = 0; i < m; i++) {
        if (arr[i] > mid || dayscount >= n) {
            return false;
        }
        if (timespend + arr[i] <= mid) {
            timespend += arr[i];
        } else {
            dayscount++;
            timespend = arr[i];
        }
    }
    return true;
}

int binary(int arr[], int n, int m) {
    int s = 0;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (ispossible(arr, n, m, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter the number of workers (n): ";
    cin >> n;
    cout << "Enter the number of tasks (m): ";
    cin >> m;

    int arr[m];
    cout << "Enter the time taken for each task:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    int result = binary(arr, n, m);
    cout << "The minimum time needed is: " << result << endl;

    return 0;
}

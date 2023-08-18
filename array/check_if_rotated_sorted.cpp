#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> arr1) {
    int n = arr1.size();
    int counter = 0;
    for (int i = 1; i < n; i++) {
        if (arr1[i - 1] > arr1[i]) { //condn for rotated array {4,5,6,7,0,1,2,3}  only one pair exits 7(i-1) > 0 (i) so it rotated 
            counter++;
        }
        if (arr1[n - 1] > arr1[0]) {//condn for sorted array {1,2,3}  only one pair exits 3(n-1) > 1 (0) so it sorted
            counter++;
        }
    }
    return counter <= 1;             //condn for equal elements {1,1,1,1,1} no pair exists 1(i-1)=1(i) so it equal 
}                                    // only arrays with one pair and 0 pair are allowed 

int main() {
    cout << "1:rotated and sorted"<<endl;
    cout << "0:not rotated and sorted"<<endl;
    vector<int> nums1 = {4, 2, 3};
    cout << "can fix" << check(nums1) << endl;  // Output should be 1 (true)

    vector<int> nums2 = {4, 2, 1};
    cout << "Can fix: " << check(nums2) << endl;  // Output should be 0 (false)

    vector<int> nums3 = {3, 4, 2, 3};
    cout << "Can fix: " << check(nums3) << endl;  // Output should be 1 (true)

    vector<int> nums4 = {1, 2, 3, 4};
    cout << "Can fix: " << check(nums4) << endl;  // Output should be 1 (true)

    vector<int> nums5 = {5, 4, 3, 2, 1};
    cout << "Can fix: " << check(nums5) << endl;  // Output should be 0 (false)

    return 0;
}

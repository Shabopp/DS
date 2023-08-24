#include<iostream>
#include<vector>
using namespace std;
void merge( vector<int>& arr,int s,int mid,int e)
{   

    vector<int> ans;
    int i=s;
    int j=mid+1;
    while(i<=mid && j<=e)
    {
        if(arr[i]<=arr[j])
        {
            ans.push_back(arr[i]);
            i++;
        }
        else
        {
            ans.push_back(arr[j]);
            j++;
        }
    }
      while(i<=mid)
    {
       
            ans.push_back(arr[i]);
            i++;
       
    }
      while(j<=e)
    {
      
    
            ans.push_back(arr[j]);
            j++;
        
    }
   for (int i = s; i <= e; i++) {
        arr[i] = ans[i - s];
    }
}
void mergesort(vector<int>& arr,int s,int e)
{
    if(s>=e)
    {
        return ;
    }
    int mid=s+(e-s)/2;
    mergesort(arr, s, mid);
    mergesort( arr, mid+1, e);
    merge( arr, s,mid,e);


}

int main() {

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    mergesort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}
/*
Initial call to mergesort(arr, 0, 6) (where 0 is the start index and 6 is the end index):

mergesort(arr, 0, 6) splits the array into two halves: mergesort(arr, 0, 3) and mergesort(arr, 4, 6).

Left half: {9, 4, 7, 6}
Right half: {3, 1, 5}

Recursively, mergesort(arr, 0, 3) further splits:

Left half: {9, 4}
Right half: {7, 6}

Recursively, mergesort(arr, 0, 1) further splits:

Left half: {9}
Right half: {4}

Since both halves have only one element, no more splitting is needed.

Merge {9} and {4} to get {4, 9}.

Moving back up the recursion, merge the left and right halves of the previous step:

Merge {4, 9} and {7, 6} to get {4, 6, 7, 9}.

Now, the left half of the initial call (mergesort(arr, 0, 3)) is sorted: {4, 6, 7, 9}.

Recursively, mergesort(arr, 4, 6) splits:

Left half: {3}
Right half: {1, 5}

Again, since both halves have only one element (or are already sorted), no more splitting is needed.

Merge {3} and {1, 5} to get {1, 3, 5}.

Moving back up the recursion, merge the left and right halves of the previous step:

Merge {3} and {1, 3, 5} to get {1, 3, 3, 5}.

Now, the right half of the initial call (mergesort(arr, 4, 6)) is sorted: {1, 3, 5}.

Finally, merge the two sorted halves of the initial call:

Merge {4, 6, 7, 9} and {1, 3, 5} to get the fully sorted array {1, 3, 4, 5, 6, 7, 9}.

The sorted array is printed, and you will see the output:

Before Sorting Array:
9 4 7 6 3 1 5
After Sorting Array:
1 3 4 5 6 7 9
*/

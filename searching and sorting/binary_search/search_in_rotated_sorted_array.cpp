// C++ Program to search an element
// in a sorted and pivoted array

#include <bits/stdc++.h>
using namespace std;

// Standard Binary Search function
int binarySearch(int arr[], int low, int high, int key)
{
   int start=low;
    int end=high;
    int mid=start + (end-start)/2;
    while(start<=end)
    {   
        if(arr[mid]==key)
        {
            return mid;
        }
        if(key>arr[mid])
        {
            start=mid+1;
        }
        else
        {   
         end=mid-1;
        }
        mid=start + (end-start)/2;       
    }
    return -1;
}

// Function to get pivot. For array 3, 4, 5, 6, 1, 2
// it returns 3 (index of 6)
int findPivot(int arr[], int low, int high)
{
   int s = low;
    int e = high;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

// Searches an element key in a pivoted
// sorted array arr[] of size n
int pivotedBinarySearch(int arr[], int n, int key)
{
	int pivot = findPivot(arr, 0, n - 1);

	 if( key >= arr[pivot] && key <= arr[n-1])
    {//BS on second line
        return binarySearch(arr, pivot, n-1, key);
    }
    else
    {//BS on first line
        return binarySearch(arr, 0, pivot - 1, key);
    }
}

// Driver program to check above functions
int main()
{
	// Let us search 3 in below array
	int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	int key = 5;

	// Function calling
	cout << "Index of the key 5 is : "
		<< pivotedBinarySearch(arr1, n, key);

	return 0;
}

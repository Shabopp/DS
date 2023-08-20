#include <iostream>
#include <vector>

using namespace std;

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int index = -1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int sumone = 0;
        for (int j = 0; j < m; j++)
        {
            sumone += matrix[i][j];
        }
        if (sumone > sum)
        {
            sum = sumone;
            index = i;
        }
    }

    return index;
}

int main()
{
    int n, m;

    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter the elements of the matrix (0 or 1):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int maxRowIndex = rowWithMax1s(matrix, n, m);

    if (maxRowIndex == -1)
    {
        cout << "No row contains 1s.\n";
    }
    else
    {
        cout << "Row with the most 1s is row " << maxRowIndex << ".\n";
    }

    return 0;
}
/*
1 0 1 1
0 1 1 0
0 0 0 1
The rowWithMax1s function is called with matrix, n (3), and m (4).

Inside rowWithMax1s:

index is initialized to -1, and sum is initialized to 0.
The function starts iterating through the rows of the matrix (from i = 0 to i = 2):

For i = 0, it calculates the sum of 1s in the first row: 1 + 0 + 1 + 1 = 3.

Since sumone (3) is greater than sum (0), it updates sum to 3 and index to 0.

For i = 1, it calculates the sum of 1s in the second row: 0 + 1 + 1 + 0 = 2.

Since sumone (2) is not greater than sum (3), no updates are made.

For i = 2, it calculates the sum of 1s in the third row: 0 + 0 + 0 + 1 = 1.

Since sumone (1) is not greater than sum (3), no updates are made.

After processing all rows, the function returns index, which is 0 (the index of the row with the most 1s).

Back in the main function, maxRowIndex is set to 0.

The code checks if maxRowIndex is -1 (it's not) and prints the result:


Row with the most 1s is row 0.
*/


/*
using binary search 
int firstocc(vector<int> arr,int n,int key)
{
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e)
    {
        if(arr[mid]==key)
        {
            ans=mid;
            e=mid-1;     
        }
        else if(key>arr[mid])
        {
            s=mid+1;
        }
        else if(key<arr[mid])
        {
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int lastocc(vector<int> arr,int n,int key)
{
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e)
    {
        if(arr[mid]==key)
        {
            ans=mid;
            s=mid+1;     
        }
        else if(key>arr[mid])
        {
            s=mid+1;
        }
        else if(key<arr[mid])
        {
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int index;
    int sum=0;
    
    
   for(int i=0; i<n; i++)
   {    
    int sumone=lastocc( matrix[i],m,1)-firstocc(matrix[i],m,1)+1;
    if(sumone>sum)
        {
         sum=sumone;
         index=i;
        }
   }
 
   return index;
   
}
*/
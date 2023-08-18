#include <iostream>
using namespace std;
//three pointers approach
//dutch national flag algorithm
void sort012(int arr[], int n)
{  
   int low=0;
   int mid=0;
   int high =n-1;
   while(mid<=high)
   {
      if(arr[mid]==0)
      {
         swap(arr[low],arr[mid]);
         mid++;
         low++;
      }
      else if(arr[mid]==1)
      {
         mid++;
      }
      else
      //if arr[mid]==2 case
      {
         swap(arr[mid],arr[high]);
         high--;
      }
   }
}
void printt(int arr[],int n)
{
    for (int k = 0; k < n; k++)
    {
        cout<<arr[k]<<" ";
    }
    
}         
int main ( )  
{  
    int arr [7] = {1,2,0,1,2,0,2} ;  
    sort012(arr,7);
    printt(arr,7);
    return 0 ;  
}  
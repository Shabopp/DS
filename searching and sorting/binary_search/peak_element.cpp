#include<iostream>
using namespace std;
int peakelement(int arr[],int n)
{   
      if(n==1)
    {
          return 0;       
    }
    if(arr[0]>arr[1])
    {
          return 0;       
    }
     if( arr[n-2]<arr[n-1])
    {
          return n-1;     
    }
   
    int s=1;
    int e=n-2;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
        
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        {
            return arr[mid];     
        }
        else if(arr[mid]>arr[mid-1])
        {
            s=mid+1;
        }
        else if(arr[mid]>arr[mid+1])
        {
           e=mid-1;
        }
        else e=mid-1;
        mid=s+(e-s)/2;
    }
    return -1;
}

int main()
{
     int arr[6]={1,2,3,4,3,2};

     cout<<"the peak element = "<<peakelement(arr,6)<<endl;

    return 0;
}

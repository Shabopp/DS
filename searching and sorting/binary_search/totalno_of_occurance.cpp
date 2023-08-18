#include<iostream>
using namespace std;
int firstocc(int arr[],int n,int key)
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
int lastocc(int arr[],int n,int key)
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
int main()
{
     int arr[6]={1,2,2,2,3,4};

     cout<<"the first occ of 2 is at index = "<<firstocc(arr,6,2)<<endl;

     cout<<"the last occ of 2 is at index = "<<lastocc(arr,6,2)<<endl;
    
    cout<<"total number of occurance of 2 is = "<<(lastocc(arr,6,2)-firstocc(arr,6,2))+1;  //total occ=(last index-first index)+1; 

    return 0;
}

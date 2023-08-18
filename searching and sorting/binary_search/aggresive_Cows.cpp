#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool ispossible(int arr[],int n,int cows,int mid)
{
   int cowCount = 1;
    int lastPos = arr[0];
    
    for(int i=0; i<n; i++ ){
        
        if(arr[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==cows)
            {
                return true;
            }
            lastPos = arr[i];
        }
    }
    return false;
}

int cows(int arr[],int n,int cows)
{
    int s=0;
    int ans=-1;
    int e=10^9;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
        sort(arr, arr+n);
        if(ispossible(arr,n,cows,mid)==true)
        {   
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;

}
int main()
{
    int arr[3]={3 ,1, 2};
    int anss=cows(arr,3,2);
    cout<<anss;

    return 0;
}

 


#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool ispossible (int a[], int k,int n,int mid)
{
    int painters=1;
    int boardsum=0;
    for(int i=0;i<n;i++)
    {
        if(boardsum+a[i]<=mid)
        {
            boardsum+=a[i];
           

        }
        else{
            painters++;
            if(painters>k||a[i]>mid)
            {
                return false;
            }

            boardsum=a[i];
                 
        }
        
    }
    return true;
}

int boardallocation(int a[], int k,int n)
{

    int s=0;

    int sum=0;

    for(int i=0;i<n;i++){

        sum+=a[i];

    }

    int e=sum;

     int mid=s+(e-s)/2;
     int ans=-1;
     while(s<=e)
     {
         if(ispossible(a,k,n,mid))
         {
             e=mid-1;
             ans=mid;
         }
         else{
             s=mid+1;
         }
         mid=s+(e-s)/2;
     }
     return ans;
}

int main(){
int n=4 ; int k =  2 ;
int a[4]={5,5,5,5};
cout<<boardallocation(a,2,4)<<endl;

    return 0;

}
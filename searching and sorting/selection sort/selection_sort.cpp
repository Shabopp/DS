#include<bits/stdc++.h>

using namespace std;
void selectionsort(int arr[],int n)
{   
    
    for(int i=0;i<n-1;i++)
    {   
        int min=i;
        for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min]){
         min=j;
        }
        swap(arr[min],arr[i]);
        }
    }   
}
void printarr(int arr[],int n){
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[6]={4,22,11,3,44,5};
    selectionsort(arr,6);
    printarr(arr,6);
    
    return 0;
}
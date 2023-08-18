#include<iostream>
using namespace std;

void movezeroes(int arr[],int n){
     int j=0;
    for(int i=0;i<n;i++)
   
    {
        if(arr[i]!=0)
        {
            swap(arr[j],arr[i]);
            j++;
        }
        

    }
}
void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
}
int main()
{
    int arr[6]={1,2,0,3,0,1};
    movezeroes(arr,6);
    printarray(arr,6);
    return 0;

}
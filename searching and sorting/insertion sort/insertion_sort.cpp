#include<iostream>
using namespace std;
void insertion(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {   
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            
            {
                swap(arr[j],arr[j-1]);
                j--;
            }
        }
    }
}

void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[5]={1,22,33,4,5};
    insertion(arr,5);
    printarray(arr,5);
    return 0;

}
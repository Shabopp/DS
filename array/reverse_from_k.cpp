#include<iostream>
using namespace std;
void reverse(int arr[],int n,int revfrom)
{
    int s=revfrom+1;
    int e=n-1;
    while(s<=e)
    {
        swap(arr[s],arr[e]);
        s++;
        e--;
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
    int arr[6]={1,2,3,5,6,7};
    reverse(arr,6,2);
    printarray(arr,6);
    return 0;

}
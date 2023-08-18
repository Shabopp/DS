#include <iostream>
using namespace std;

void reverse ( int arr [ ] , int n )  
{  
         int i=0;
         int j=n-1;
           while(i<j){
           while(arr[i]==0 && i<j)
        {
             i++; 
        }
           while(arr[j]==1 && i<j)
        {
             j--;
        }
           if( i<j)
        {
             swap(arr[i],arr[j]);
             i++;
             j--;
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
    int arr [7] = {1,0,1,1,1,0,0} ;  
    reverse(arr,7);
    printt(arr,7);
    return 0 ;  
}  
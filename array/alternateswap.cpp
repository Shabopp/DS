#include <iostream>
using namespace std;

void alternate( int arr [ ] , int n )  
{  
    for ( int i = 0; i < n; i+=2)
    {
         if(arr[i+1<n])
   {
     swap(arr[i],arr[i+1]);
   }               
    }    
}
void printt(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
    cout<<endl;    
}         
int main ( )  
{  
    int arr [6] = { 10 , 324 , 45 , 90 , 0,8} ;  
    alternate(arr,6);
    printt(arr,6);
    return 0 ;  
}  
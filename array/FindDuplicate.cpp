#include <iostream>
using namespace std;

int FIndDuplicate( int arr [ ] , int n )  
{   
    int ans=0;
    for ( int i = 0; i < n; i++)
    {
        ans=ans^arr[i];             
    }  
     for ( int i = 1; i < n; i++)
    {
        ans=ans^i;             
    } 
    cout<<ans; 
     
    return 0;
}       
int main ( )  
{  
    int arr [6] = {3,5,4,10,2,2} ;  
    FIndDuplicate(arr,6);
    return 0 ;  
}  
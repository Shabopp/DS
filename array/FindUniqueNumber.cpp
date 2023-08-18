#include <iostream>
using namespace std;

int Unique( int arr [ ] , int n )  
{   
    int ans=0;
    for ( int i = 0; i < n; i++)
    {
        ans=ans^arr[i];             
    }  
    cout<< ans;  
    return 0;
}       
int main ( )  
{  
    int arr [7] = {3,5,3,7,5,2,2} ;  
    Unique(arr,7);
    return 0 ;  
}  
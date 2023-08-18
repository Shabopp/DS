#include <iostream>
using namespace std;

int largest ( int arr [ ] , int n )  
{  
    int i ;   
    // Initialize maximum element  
    int max = arr [ 0 ] ;   
   
    for ( i = 1 ; i < n ; i++)  
        if ( arr [ i ] > max ) 
            max = arr [ i ] ;  
    return max ;  
}  
int smallest ( int arr [ ] , int n )  
{ 
    int i ;   
    // Initialize maximum element  
    int min = arr [ 0 ] ;   
  
    for ( i = 1 ; i < n ; i++)  
        if ( arr [ i ] < min ) 
            min = arr [ i ] ;  
    return min ;  
}  

int main ( )  
{  
    int arr [ ] = { 10 , 324 , 45 , 90 , 0} ;  
    int n = sizeof ( arr ) / sizeof (arr [ 0 ] ) ;  
    cout << " Largest in given array is " << largest ( arr , n )<<endl ;  
    cout << " smalllest in given array is " << smallest ( arr , n ) ;  
    return 0 ;  
}  
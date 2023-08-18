#include<iostream>
using namespace std;
int main()
{    
    int n;
    cin>>n;
     int rem;
    int rev;
    while (n!=0)
   {  
     rem=n %10;
     if ((n>INT_MAX/10)||(n<INT_MIN/10))
     {
      cout<<0;
     }
     
     rev=(10*rev)+rem;   
     n=n/10;

    }
    cout<< rev;
    
}
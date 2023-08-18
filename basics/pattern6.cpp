#include<iostream>
using namespace std;
int main()
{    
    int n;
    cin>>n; 
    int i=1; 
    char counter='A';
    while(i<=n)
    {
        
        int j=1;
        while(j<=n)
        {   
            char ch=counter;
            cout<<ch;
            counter=counter+1;
            
            j=j+1;
            
        }
        cout<<endl;
        i=i+1;

    }
}
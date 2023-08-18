#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    int i=1;
// logic for summation of odd n numbers using while lopp
    while(i<=n)
    {
        sum+=i;
        i=i+2;
       
    }
     cout<<"sum is = "<<sum<<endl;
}
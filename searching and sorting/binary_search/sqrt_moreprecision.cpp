#include<iostream>
using namespace std;
long long int tempsol(int n)
{
    int s=0;
    int e=n;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e)
    {
        long long int square=mid*mid;
        if(square==n)
        {
            return mid;
        }
        else if(square>n)
        {   
            e=mid-1;
        }
        else{
            ans=mid;
            s=mid+1;
        }
         mid=s+(e-s)/2;

    }
    return ans;

}
double moreprecision(int n,int precision ,int temp)
{   
    double factor = 1;
    double  ans=temp;
    for(int i=0;i<precision;i++)
    {
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor)
        {
            ans=j;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int temp=tempsol(n);
    cout<<moreprecision(n,5,temp);
}
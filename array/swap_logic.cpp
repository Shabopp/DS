#include<iostream>
using namespace std;
int main()
{   
    int temp;
    int arr[4]={1,2,3,4};
    cout<<"initial array = ";
        for(int i=0;i<4;i++){
            
    cout<<arr[i]<<" ";
  
    }
    cout<<endl;
    
   
    temp=arr[1];
    arr[1]=arr[0];
    arr[0]=temp;


    cout<<"after swaping array = ";
    for(int i=0;i<4;i++){
    cout<<arr[i]<<" ";
    }
    



    return 0;
}

#include<iostream>
using namespace std;
bool search(int arr[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(key==arr[i])
        {
            return 1;   
        }       
    }
    return 0;
}

int main()
{
    int arr[10]={2,3,4,51,6,7,5,3,8,78};
    cout<<"enter the key";
    int key;
    cin>>key;
    bool found= search( arr,10,key);
    if (found){
        cout<<"key is present";
    }
    else{
        cout<<"key is absent";
    }
    return 0;
}
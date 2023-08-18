#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;
    int mid=start + (end-start)/2;
    while(start<=end)
    {   
        if(arr[mid]==key)
        {
            return mid;
        }
        if(key>arr[mid])
        {
            start=mid+1;
        }
        else
        {   
         end=mid-1;
        }
        mid=start + (end-start)/2;       
    }

     return -1;

}

int main()
{
    int evenarr[6]={1,2,4,5,6,7};

    int oddarr[5]={1,3,4,5,6};

    int evenindex=binarysearch(evenarr,6,4);
    cout<<"index of 4 is "<<evenindex<<endl;

    int oddindex=binarysearch(oddarr,5,3);
    cout<<"index of 3 is "<<oddindex<<endl;
}

#include<iostream>
using namespace std;
bool checksorted(int arr[],int size)
{
    if(size==0 || size==1)
    {
        return true;
    }

    if(arr[0]>arr[1])
    {
        return false;
    }
    else{
    bool remainingpart= checksorted(arr+1,size-1);
    return remainingpart;
    }
    
}

int main()
{
    int arr[5]={1,2,0,4,5};
    if( checksorted(arr,5))
    {
        cout<<"sorted";
    }
    else{
        cout<<"unsorted";
    }

    return 0;

}
/*
Initial Call: checksorted(arr, 5)

size is 5, which is not equal to 0 or 1, so it proceeds to the if statement.
It checks if arr[0] (which is 1) is greater than arr[1] (which is 2). Since 1 is not greater than 2, it proceeds to the else block.
In the else block, it makes a recursive call checksorted(arr + 1, size - 1) which is checksorted(arr + 1, 4).
Recursive Call 1: checksorted(arr + 1, 4)

size is 4, which is not equal to 0 or 1, so it proceeds to the if statement.
It checks if arr[0] (which is now 2) is greater than arr[1] (which is 0). Since 2 is not greater than 0, it returns false.
Since the first recursive call returned false, the checksorted function in the main function also returns false. Therefore, the output of this code will be "unsorted."

In this case, the array {1, 2, 0, 4, 5} is not sorted in non-decreasing order, and the code correctly identifies it as "unsorted."
/*